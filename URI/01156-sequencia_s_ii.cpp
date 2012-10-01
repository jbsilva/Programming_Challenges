// ============================================================================
// 
//       Filename:  01156-sequencia_s_ii.cpp
// 
//    Description:  URI 1156 - Sequência S II
// 
//        Version:  1.0
//        Created:  09/30/2012 08:48:08 PM
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
    long double s=0;

    for (int i=1, j=1; i<=39; i+=2, j*=2)
        s += (double)i/j;

    printf("%.2Lf\n", s);

    return 0;
}
