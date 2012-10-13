// ============================================================================
// 
//       Filename:  01250-kiloman.cpp
// 
//    Description:  Problema de simulação retirado do TopCoder:
//                  community.topcoder.com/stat?c=problem_statement&pm=2268
//                  Adaptado para o URI Online Judge por mim
// 
//        Version:  1.0
//        Created:  10/05/2012 12:01:05 AM
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
    int altura[51], tiros, hits, casos;
    char jump;

    scanf("%d", &casos);
    while (casos--)
    {
        scanf("%d", &tiros);          // Número de tiros = tamanho da sequencia
        for (int i=0; i < tiros; i++)
            scanf("%d ", &altura[i]);

        hits = 0;
        for (int i=0; i < tiros; i++)
        {
            jump = getchar();
            if (jump == 'S' && altura[i] <= 2 || jump == 'J' && altura[i] > 2)
                hits++;
        }

        printf("%d\n", hits);
    }

    return 0;
}
