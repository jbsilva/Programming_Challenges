// ============================================================================
//
//       Filename:  01259-pares_e_impares.cpp
//
//    Description:  URI 1259 - Pares e Ímpares
//
//        Version:  1.0
//        Created:  29/Oct/2012 15:11:22
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstdlib>


inline int comp_int(const void* a, const void* b)
{
    // Nao vai dar overlow, pois a > 0 e b > 0
    return (*(int*)a - * (int*)b);
}


int main()
{
    int n, num, qtd_p = 0, qtd_i = 0;
    int pares[1000001], impares[1000001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        if (num % 2)
        {
            impares[qtd_i] = num;
            qtd_i++;
        }
        else
        {
            pares[qtd_p] = num;
            qtd_p++;
        }
    }
    qsort(pares, qtd_p, sizeof(int), comp_int);
    qsort(impares, qtd_i, sizeof(int), comp_int);
    for (int i = 0; i < qtd_p; i++)
        printf("%d\n", pares[i]);
    for (int i = qtd_i - 1; i >= 0; i--)
        printf("%d\n", impares[i]);
    return 0;
}
