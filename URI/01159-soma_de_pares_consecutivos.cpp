// ============================================================================
//
//       Filename:  01159-soma_de_pares_consecutivos.cpp
//
//    Description:  URI 1159 - Soma de Pares Consecutivos
//
//        Version:  1.0
//        Created:  09/30/2012 10:36:45 PM
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
    int x;
    while (scanf("%d", &x) && x)
    {
        if (x % 2)
            x++;
        int i = 5, sum = 0;
        while (i--)
        {
            sum += x;
            x += 2;
        }
        printf("%d\n", sum);
    }
    return 0;
}
