// ============================================================================
//
//       Filename:  01115-quadrante.cpp
//
//    Description:  URI 1115 - Quadrante
//
//        Version:  1.0
//        Created:  09/30/2012 02:16:08 PM
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
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF && (x || y))
    {
        if (y > 0)
            if (x > 0)
                puts("primeiro");
            else
                puts("segundo");
        else if (x < 0)
            puts("terceiro");
        else
            puts("quarto");
    }
    return 0;
}
