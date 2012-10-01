// ============================================================================
// 
//       Filename:  01143-quadrado_e_ao_cubo.cpp
// 
//    Description:  URI 1143 - Quadrado e ao Cubo
// 
//        Version:  1.0
//        Created:  09/30/2012 03:48:19 PM
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

    int i = 1;
    while (n--)
    {
        printf("%d %d %d\n", i, i*i, i*i*i);
        i++;
    }

    return 0;
}
