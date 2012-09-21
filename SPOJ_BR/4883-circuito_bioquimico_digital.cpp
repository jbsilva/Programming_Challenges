// ============================================================================
// 
//       Filename:  4883-circuito_bioquimico_digital.cpp
// 
//    Description:  Primeira fase da Maratona de Programação - 2006
//                  br.spoj.pl/problems/CIRCUITO/
// 
//        Version:  1.0
//        Created:  09/14/2012 12:49:14 AM
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
    char m[1001][1001];
    int p, n, c; // pontos, medições, comprimento mínimo

    while (scanf("%d %d %d", &p, &n, &c) && (p || n || c))
    {
        for (int i=0; i < n; i++)
            for (int j=0; j < p; j++)
                scanf("%d", &m[i][j]);    // Cast int->char. scanf não tem bool

        int palitos = 0;
        for (int j=0; j < p; j++)
        {
            int i=0;
            while (i < n)
            {
                while (i < n && m[i][j] == 0)
                    i++;

                int tam = 0;
                while (i < n && m[i][j] == 1)
                {
                    tam++;
                    i++;
                }
                if (tam >= c) palitos ++;
            }
        }

        printf("%d\n", palitos);
    }
    return 0;
}
