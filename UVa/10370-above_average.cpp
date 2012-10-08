// ============================================================================
// 
//       Filename:  10370-above_average.cpp (UVa)
//                  01214-above_average.cpp (URI)
//                  02350-above_average.cpp (POJ)
// 
//    Description:  UVa 10370 - Above Average
//                  URI 1214 - Above Average
//                  POJ 2350 - Above Average
// 
//        Version:  1.0
//        Created:  08/Oct/2012 01:19:30
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

int main()
{
    int nota[1001];

    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        int qtd;
        scanf("%d", &qtd);

        int soma = 0;
        for (int i=0; i < qtd; i++)
        {
            scanf("%d", &nota[i]);
            soma += nota[i];
        }

        double media = (double)soma/qtd;
        int acima = 0;
        for (int i=0; i < qtd; i++)
            if (nota[i] > media)
                acima++;

        printf("%.3lf%%\n", 100.0*acima/qtd);
    }

    return 0;
}
