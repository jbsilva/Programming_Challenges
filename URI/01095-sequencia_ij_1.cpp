// ============================================================================
// 
//       Filename:  01095-sequencia_ij_1.cpp
// 
//    Description:  URI 1095 - Sequencia IJ 1
// 
//        Version:  1.0
//        Created:  09/30/2012 01:32:06 AM
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
    int i,j;
    for (i=1, j=60; j>=0; i+=3, j -= 5)
        printf("I=%d J=%d\n", i, j);

    return 0;
}
