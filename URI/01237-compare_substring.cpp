// ============================================================================
//
//       Filename:  01237-compare_substring.cpp
//
//    Description:  URI 1237 - Compare Substring
//                  Problema adaptado do Topcoder
//
//                  Implementação do "Skew Algorithm" (DC3 - Difference Cover
//                  modulo 3) baseada no paper "Simple Linear Work Suffix Array
//                  Construction" por Juha Kärkkäinen e Peter Sanders, 2003.
//
//                  O Skew Algorithm cria o suffix array da string S em
//                  O(|S| + sort(Σ)) == O(|S| + n) == O(n) com o radix sort.
//
//                  Encontrei boas explicações sobre este algoritmo em:
//                    http://cs.helsinki.fi/u/tpkarkka/publications/icalp03.pdf
//                    http://felix-halim.net/pg/suffix-array/index.php
//                    Data Structures & Algorithms Analysis in Java - 3ed
//                    MIT 6.851 - Advanced Data Structures - Aula 16
//
//        Version:  1.0
//        Created:  02/Mar/2013 22:06:46
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
using namespace std;


// Counting sort baseado no CLRS 3ed.
// out[0..len-1] será o in[0..len-1] ordenado.
// Ss será sempre uma substring de S (um ponteiro para S mais um offset).
// Ss deverá conter apenas inteiros em [0..tam_alfa]
// No paper esta etapa é chamada de "radixPass".
void counting_sort(const int* in, int* out, const int* Ss, int len, int tam_alfa)
{
    // c[ch] -> Quantidade de ocorrências do caractere ch
    int* c = new int[tam_alfa + 1];
    memset(c, 0, (tam_alfa + 1) * sizeof(int));
    for (int i = 0; i < len; i++)
        c[Ss[in[i]]]++;
    // Depois do loop, c[i] conterá o número de elementos menores ou iguais a i
    for (int i = 1; i <= tam_alfa; i++)
        c[i] += c[i - 1];
    for (int i = len - 1; i >= 0; i--)
        out[--c[Ss[in[i]]]] = in[i];
    delete[] c;
}


// Compara pares: [a1 a2] <= [b1 b2]
inline bool leq(int a1, int a2, int b1, int b2)
{
    return (a1 < b1 || (a1 == b1 && a2 <= b2));
}


// Compara triplas: [a1 a2 a3] <= [b1 b2 b3]
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3)
{
    return (a1 < b1 || (a1 == b1 && leq(a2, a3, b2, b3)));
}


void merge(int* S, int* SA, int len,
           int* S12, int* SA12, int len12,
           int* SA0,  int len0, int j)
{
    for (int i = 0, k = 0; k < len;)
    {
        int a = SA0[i];
        int b = (SA12[j] < len0 ? SA12[j] * 3 + 1 : (SA12[j] - len0) * 3 + 2);
        if (b % 3 == 1 ? leq(S[a], S12[a / 3],
                             S[b], S12[b / 3 + len0]) :
                leq(S[a], S[a + 1], S12[a / 3 + len0],
                    S[b], S[b + 1], S12[b / 3 + 1]))
        {
            SA[k++] = a;
            if (++i == len0)
                while (k < len)
                    SA[k++] = (SA12[j] < len0 ? SA12[j++] * 3 + 1 : (SA12[j++] - len0) * 3 + 2);
        }
        else
        {
            SA[k++] = b;
            if (++j == len12)
                while (k < len)
                    SA[k++] = SA0[i++];
        }
    }
}


// Função recursiva que preenche "SA" com o suffix array (permutação de
// [0..len-1]) da string representada pelo vetor de ints "S", de tamanho "len".
// Requisitos: (S[len] = S[len+1] = S[len+2] = 0) e (len >= 2).
void suffix_array(int* S, int len, int tam_alfabeto, int* SA)
{
    // Dividir a string S em 3 partes (armezenar apenas índices):
    //   S0 -> "len0" triplas iniciadas em posição i%3=0;
    //   S1 -> "len1" triplas iniciadas em posição i%3=1;
    //   S2 -> "len2" triplas iniciadas em posição i%3=2;
    int len0 = (len + 2) / 3, len1 = (len + 1) / 3, len2 = len / 3;
    // S12 -> S1 concatenada com S2. Contém "len12" índices de triplas, mas
    // vamos alocar mais 3 posições para os zeros que completam as triplas.
    int len12 = len1 + len2;
    // Se os tamanhos de S1 e S0 forem diferentes (acontece quando len%3==1),
    // adiciona o sufixo '000' a S1 para ficarem iguais (é mais cômodo assim).
    int pad = len0 - len1;
    len12 += pad;
    int* S12 = new int[len12 + 3];
    S12[len12] = S12[len12 + 1] = S12[len12 + 2] = 0;
    // Gera S12, que contém os índices das triplas em S1 e S2.
    for (int i = 0, j = 0; i < len + pad; i++)
        if (i % 3)
            S12[j++] = i;
    // SA12 -> Suffix Array só dos sufixos pertencentes a S1 e S2
    int* SA12 = new int[len12 + 3];
    SA12[len12] = SA12[len12 + 1] = SA12[len12 + 2] = 0;
    // Ordena as triplas de S12 usando um "least significant digit radix sort"
    counting_sort(S12, SA12, S + 2, len12, tam_alfabeto); // 3o ch das triplas
    counting_sort(SA12, S12, S + 1, len12, tam_alfabeto); // 2o ch das triplas
    counting_sort(S12, SA12, S    , len12, tam_alfabeto); // 1o ch das triplas
    // Renomeia as triplas de S12 de forma lexicográfica a partir do 1
    int name = 0;
    int c0 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < len12; i++)
    {
        // Compara a tripla atual, [ti..ti+2], com tripla anterior
        int ti = SA12[i];
        if (S[ti] != c0 || S[ti + 1] != c1 || S[ti + 2] != c2)
        {
            name++;
            c0 = S[ti];
            c1 = S[ti + 1];
            c2 = S[ti + 2];
        }
        if (ti % 3 == 1)         // ti%3=1 -> ti é de S1, a metade da esquerda.
            S12[ti / 3] = name;
        else                     // ti%3=2 -> ti é de S2, a metade da direita.
            S12[ti / 3 + len0] = name; // len0 = len1+pad
    }
    if (name == len12) // Nomes únicos. Não precisa recursar
    {
        for (int i = 0; i < len12; i++)
            SA12[S12[i] - 1] = i;
    }
    else
    {
        // Existem triplas repetidas. Recursão
        suffix_array(S12, len12, name, SA12);
        for (int i = 0; i < len12; i++)
            S12[SA12[i]] = i + 1;
    }
    // Ordena os sufixos em S0 a partir de SA12 pelo primeiro caractere
    int* S0 = new int[len0];
    int* SA0 = new int[len0];
    for (int i = 0, j = 0; i < len12; i++)
        if (SA12[i] < len0)
            S0[j++] = 3 * SA12[i];
    counting_sort(S0, SA0, S, len0, tam_alfabeto);
    // Merge SA0 e SA12
    merge(S, SA, len, S12, SA12, len12, SA0, len0, pad);
    delete[] S12; delete[] SA12; delete[] SA0; delete[] S0;
}


// Converte o vetor de caracteres "a_char" no vetor de inteiros "a_int".
// O map "num_letra" associa números (de 1 até o tamanho do alfabeto) a
// caracteres do alfabeto, de forma ordenada.
// Retorna o tamanho do alfabeto.
int char2int(char* a_char, int len, int* a_int)
{
    set<char> alfabeto;
    set<char>::iterator ch;
    map<char, int> num_letra;
    for (int i = 0; i < len; i++)
        alfabeto.insert(a_char[i]);
    ch = alfabeto.begin();
    for (int ordem = 1; ch != alfabeto.end(); ++ch, ordem++)
        num_letra[*ch] = ordem;
    for (int i = 0; i < len; i++)
        a_int[i] = num_letra[a_char[i]];
    return (int)alfabeto.size();
}


// Overload para simplificar a chamada da função.
// Retorna se deu para processar
bool suffix_array(char* S, int* SA)
{
    int len = strlen(S);
    if (len < 2) return false; // Nunca vai acontecer neste problema
    int* str_int = new int[len + 3];
    int tam_alfabeto = char2int(S, len, str_int);
    str_int[len] = str_int[len + 1] = str_int[len + 2] = 0;
    suffix_array(str_int, len, tam_alfabeto, SA);
    return true;
}


void lcp_array(char* S, int* SA, int n, int* LCP)
{
    int* Phi = new int[n];
    int* PLCP = new int[n];
    int i, L;
    Phi[SA[0]] = -1;                                           // default value
    for (i = 1; i < n; i++)                              // compute Phi in O(n)
        Phi[SA[i]] = SA[i - 1];  // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++)                 // compute Permuted LCP in O(n)
    {
        if (Phi[i] == -1)
        {
            PLCP[i] = 0;    // special case
            continue;
        }
        // L will be increased max n times
        while (S[i + L] == S[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0);                   // L will be decreased max n times
    }
    // put the permuted LCP back to the correct position
    for (i = 1; i < n; i++)
        LCP[i] = PLCP[SA[i]];
    delete[] Phi; delete[] PLCP;
}


int lcs(int* SA, int* LCP, int tam, int tam1)
{
    int max_lcp = -1;
    for (int i = 1; i < tam; i++)
        if (LCP[i] > max_lcp && ((SA[i - 1] < tam1) != (SA[i] < tam1)))
            max_lcp = LCP[i];
    return max_lcp;
}


int main()
{
    // Strings de entrada
    char str[200], str2[100];
    int SA[200]; // Suffix Array
    int LCP[200]; // Longest Common Prefix
    while (gets(str) != NULL)
    {
        int tam1 = (int)strlen(str);
        str[tam1] = '.'; str[tam1 + 1] = '\0';
        strcat(str, gets(str2));
        int tam = (int)strlen(str);
        suffix_array(str, SA);
        lcp_array(str, SA, tam, LCP);
        printf("%d\n", lcs(SA, LCP, tam, tam1));
    }
    return 0;
}

