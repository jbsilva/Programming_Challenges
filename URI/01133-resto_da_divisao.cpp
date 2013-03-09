// ============================================================================
//
//       Filename:  01133-resto_da_divisao.cpp
//
//    Description:  URI 1133 - Resto da Divisão
//
//        Version:  1.0
//        Created:  09/30/2012 03:22:18 PM
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
    int n1, n2, min, max;
    scanf("%d %d", &n1, &n2);
    if (n1 > n2)
    {
        max = n1;
        min = n2;
    }
    else
    {
        max = n2;
        min = n1;
    }
    for (int i = min + 1; i < max; i++)
        if (i % 5 == 2 || i % 5 == 3)
            printf("%d\n", i);
    return 0;
}
