// ============================================================================
// 
//       Filename:  11610-guarda_costeira.cpp (SPOJ BR)
//                  01247-guarda_costeira.cpp (URI)
// 
//    Description:  SPOJ BR 11610 - Guarda Costeira
//                  URI 1247 - Guarda Costeira
//                  Primeira fase da Maratona de Programação - 2011
// 
//        Version:  1.0
//        Created:  11/Oct/2012 00:38:23
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cmath>

int main()
{
    int vf, vg, d;
    double dg;

    while (scanf("%d %d %d", &d, &vf, &vg) != EOF)
    {
        dg = hypot(12, d);

        puts(dg/vg <= 12.0/vf ? "S" : "N");
    }

    return 0;
}
