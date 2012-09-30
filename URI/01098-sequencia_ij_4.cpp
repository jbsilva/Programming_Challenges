// ============================================================================
// 
//       Filename:  01098-sequencia_ij_4.cpp
// 
//    Description:  URI 1098 - Sequencia IJ 4
// 
//        Version:  1.0
//        Created:  09/30/2012 01:46:12 AM
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
    double i, j;
    for (i=0; i <= 2; i+= 0.2)
    {
        j = 1+i;
        printf("I=%.2lg J=%.2lg\n", i, j++);
        printf("I=%.2lg J=%.2lg\n", i, j++);
        printf("I=%.2lg J=%.2lg\n", i, j++);
    }
    return 0;
}
