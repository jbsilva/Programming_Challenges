// ============================================================================
// 
//       Filename:  01116-dividindo_x_por_y.cpp
// 
//    Description:  URI 1116 - Dividindo X por Y
// 
//        Version:  1.0
//        Created:  09/30/2012 02:23:42 PM
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
    int cases;
    scanf("%d", &cases);

    int x, y;
    while (cases--)
    {
        scanf("%d %d", &x, &y);

        if (y == 0)
            puts("divisao impossivel");
        else
            printf("%g\n", (double)x/y);
    }

    return 0;
}
