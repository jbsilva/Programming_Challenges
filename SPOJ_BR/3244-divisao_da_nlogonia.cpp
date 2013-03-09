// ============================================================================
//
//       Filename:  01091-divisao_da_nlogonia.cpp (URI)
//                  3244-divisao_da_nlogonia.cpp (SPOJ BR)
//                  11498-division_of_nlogonia.cpp (UVa)
//
//    Description:  URI 1091 - Divisão da Nlogônia
//                  Primeira fase da Maratona de Programação - 2008
//                  br.spoj.pl/problems/NLOGONIA/
//
//        Version:  1.0
//        Created:  08/12/2012 02:47:19 PM
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
    int consultas, n, m, x, y, i;
    scanf("%d", &consultas);
    while (consultas)
    {
        scanf("%d %d", &n, &m);
        for (i = 0; i < consultas; i++)
        {
            scanf("%d %d", &x, &y);
            if (x == n || y == m)
                puts("divisa");
            else
            {
                if (x > n && y > m)
                    puts("NE");
                else if (x < n && y > m)
                    puts("NO");
                else if (x < n && y < m)
                    puts("SO");
                else if (x > n && y < m)
                    puts("SE");
            }
        }
        scanf("%d", &consultas);
    }
    return 0;
}
