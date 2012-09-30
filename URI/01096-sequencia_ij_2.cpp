// ============================================================================
// 
//       Filename:  01096-sequencia_ij_2.cpp
// 
//    Description:  URI 1096 - Sequencia IJ 2
// 
//        Version:  1.0
//        Created:  09/30/2012 01:35:34 AM
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
    for (int i=1; i<=9; i+=2)
        for (int j=7; j>=5; j--)
            printf("I=%d J=%d\n", i, j);

    return 0;
}
