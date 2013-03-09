// ============================================================================
//
//       Filename:  01158-soma_de_impares_consecutivos_iii.cpp
//
//    Description:  URI 1158 - Soma de Ímpares Consecutivos III
//
//        Version:  1.0
//        Created:  09/30/2012 10:31:18 PM
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
    while (n--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x % 2 == 0)
            x += 1;
        int sum = 0;
        while (y--)
        {
            sum += x;
            x += 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
