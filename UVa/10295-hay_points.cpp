// ============================================================================
//
//       Filename:  10295-hay_points.cpp (UVa)
//                  01261-hay_points.cpp (URI)
//
//    Description:  UVa 10295 - Hay Points
//                  URI 1261 - Hay Points
//
//        Version:  1.0
//        Created:  01/Mar/2013 22:28:22
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{
    int M, N; // M -> palavras no dicionário; N -> qtd de job descriptions
    char word[17];
    int valor, soma; // O texto diz "real number" querendo dizer inteiro...
    map<string, int> pvals; // valor das palavras
    scanf("%d %d", &M, &N);
    while (M--)
    {
        scanf("%s %d", &word, &valor);
        pvals[string(word)] = valor;
    }
    while (N--)
    {
        soma = 0.0;
        while (scanf("%s", &word) && word[0] != '.')
            soma += pvals[string(word)];
        printf("%d\n", soma);
    }
    return 0;
}

