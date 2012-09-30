// ============================================================================
// 
//       Filename:  01172-substituicao_em_vetor_i.cpp
// 
//    Description:  URI 1172 - Substituição em Vetor I
// 
//        Version:  1.0
//        Created:  09/29/2012 07:40:03 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int x;
    for (int i=0; i < 10; i++)
    {
        scanf("%d", &x);
        if (x <= 0) x = 1;
        printf("X[%d] = %d\n", i, x);
    }
    return 0;
}
