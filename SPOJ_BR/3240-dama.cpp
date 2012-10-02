// ============================================================================
// 
//       Filename:  3240-dama.cpp  (SPOJ BR)
//                  01087-dama.cpp (URI)
// 
//    Description:  Primeira fase da Maratona de Programação - 2008
//                  br.spoj.pl/problems/DAMA/
// 
//        Version:  1.1
//        Created:  09/13/2012 09:44:33 PM
//       Revision:  02/10/2012 06:19:00 PM
//                      Troquei iostream por cstdio para conseguir 0.000s
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

inline int abs(int a)
{
    return a<0 ? -1*a : a;
}

int main()
{
    int x1, x2, y1, y2;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && (x1 || y1 || x2 || y2))
    {
        // mesma casa
        if (x1 == x2 && y1 == y2)
            puts("0");
        // está na mesma linha ou mesma coluna
        else if (x1 == x2 || y1 == y2)
            puts("1");
        // mesma diagonal
        else if (abs(x2 - x1) == abs(y2 - y1))
            puts("1");
        else
            puts("2");
    }
    return 0;
}
