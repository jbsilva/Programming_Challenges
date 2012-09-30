// ============================================================================
// 
//       Filename:  01073-quadrado_de_pares.cpp
// 
//    Description:  URI 1073 - Quadrado de Pares
// 
//        Version:  1.0
//        Created:  09/29/2012 07:04:53 PM
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
    int n;
    scanf("%d", &n);

    for (int i=2; i <= n; i+=2)
        printf("%d^2 = %d\n", i, i*i);

    return 0;
}
