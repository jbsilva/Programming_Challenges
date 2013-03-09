// ============================================================================
//
//       Filename:  01097-sequencia_ij_3.cpp
//
//    Description:  URI 1097 - Sequencia IJ 3
//
//        Version:  1.0
//        Created:  09/30/2012 01:39:03 AM
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
    int i, j;
    for (i = 1; i <= 9; i += 2)
    {
        j = 6 + i;
        printf("I=%d J=%d\n", i, j--);
        printf("I=%d J=%d\n", i, j--);
        printf("I=%d J=%d\n", i, j);
    }
    return 0;
}
