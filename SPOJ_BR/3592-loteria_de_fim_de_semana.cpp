// ============================================================================
//
//       Filename:  3592-loteria_de_fim_de_semana.cpp (SPOJ BR)
//                  01407-loteria_de_fim_de_semana.cpp (SPOJ BR)
//
//    Description:  SPOJ BR 3592 - Loteria de fim de semana
//                  URI 1407 - Loteria de fim de semana
//
//                  TODO: Verificar se fica mais rápido usando Selection Sort.
//
//        Version:  1.0
//        Created:  16/Jun/2013 23:06:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstdlib>


struct numero
{
    int n, qtd;
};


inline int comp(const void *a, const void *b)
{
    return ((numero *)a)->qtd - ((numero *)b)->qtd;
}


int main()
{
    numero numeros[101];
    int N, C, K, sorteado;
    while (scanf("%d %d %d", &N, &C, &K) && (N || C || K))
    {
        for (int i = 1; i <= K; i++)
        {
            numeros[i].n = i;
            numeros[i].qtd = 0;
        }
        for (int dia = 0; dia < N; dia++)
            for (int num = 0; num < C; num++)
            {
                scanf("%d", &sorteado);
                numeros[sorteado].qtd++;
            }
        qsort(&numeros[1], K, sizeof(numero), comp);
        printf("%d", numeros[1].n);
        for (int i = 2; i <= K && numeros[i].qtd == numeros[1].qtd; i++)
            printf(" %d", numeros[i].n);
        putchar('\n');
    }
    return 0;
}

