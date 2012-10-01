// ============================================================================
// 
//       Filename:  01157-divisores_i.cpp
// 
//    Description:  URI 1157 - Divisores I
// 
//        Version:  1.0
//        Created:  09/30/2012 08:56:40 PM
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

    for (int i=1; i <= n/2; i++)
        if (n % i == 0)
            printf("%d\n", i);
    printf("%d\n", n);

    return 0;
}
