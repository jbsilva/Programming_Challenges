// ============================================================================
//
//       Filename:  10008-whats_cryptanalysis.cpp
//
//    Description:  UVa 10008 - What's Cryptanalysis?
//
//        Version:  1.0
//        Created:  11/Jul/2013 18:58:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>


struct letra
{
    char c;
    int qtd;
};


inline int comp(const void *a, const void *b)
{
    letra ca = *(letra *)a;
    letra cb = *(letra *)b;
    if (ca.qtd > cb.qtd)
        return -1;
    if (ca.qtd < cb.qtd)
        return 1;
    if (ca.c < cb.c)
        return -1;
    else
        return 1;
}


int main()
{
    letra chrs[30];
    int n;
    char lin[500];

    // Inicializa
    for (char i = 'A'; i <= 'Z'; i++)
    {
        chrs[(int)i - 'A'].c = i;
        chrs[(int)i - 'A'].qtd = 0;
    }

    scanf("%d ", &n);
    while (n--)
    {
        int tam = strlen(gets(lin));
        for (int i = 0; i < tam; i++)
        {
            if (lin[i] >= 'A' && lin[i] <= 'Z')
                chrs[lin[i] - 'A'].qtd++;
            else if (lin[i] >= 'a' && lin[i] <= 'z')
                chrs[lin[i] - 'a'].qtd++;
        }
    }

    qsort(chrs, 26, sizeof(letra), comp);

    int i = 0;
    while (i < 26 && chrs[i].qtd)
    {
        printf("%c %d\n", chrs[i].c, chrs[i].qtd);
        i++;
    }

    return 0;
}

