// ============================================================================
//
//       Filename:  a-consonants.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/May/2013 06:04:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>



// Verifica se tem n uns no intervalo s[l..r]
bool tem_n1s(char *s, int l, int r, int n)
{
    string str(
    return false;
}


int bruteforce(char *s, int len, int n)
{
    int soma = 0;
    for (int l = 0; l <= len - n; l++)
        for (int r = l+n-1; r < len; r++)
            if (tem_n1s(s, l, r))
            {
                soma += len - r;
                break;
            }

    return soma;
}


void converte(char *s, int len)
{
    for (int i = 0; i < len; i++)
        switch(s[i])
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': s[i] = 0; break;
            default: s[i] = (char)1;
        }
}


int main()
{
    int cases, n;
    char nome[1005000];

    scanf("%d", &cases);

    for (int caso = 1; caso <= cases; caso++)
    {
        scanf("%s %d", nome, &n); getchar();
        int len = strlen(nome);

        converte(nome, len);
        int nvalue = bruteforce(nome, len, n);

        printf("Case %d: %d\n", caso, nvalue);
    }

    return 0;
}

