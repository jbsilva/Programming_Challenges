// ============================================================================
// 
//       Filename:  01039-flores_de_fogo.cpp
// 
//    Description:  URI 1039 - Flores de Fogo
// 
//        Version:  1.0
//        Created:  10/05/2012 04:48:08 PM
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
    int r1, x1, y1, r2, x2, y2;
    while (scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF)
    {
        if (r1 >= hypot(x2-x1, y2-y1) + r2)
            puts("RICO");
        else
            puts("MORTO");
    }

    return 0;
}
