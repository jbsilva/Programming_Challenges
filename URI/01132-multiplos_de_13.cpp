// ============================================================================
//
//       Filename:  01132-multiplos_de_13.cpp
//
//    Description:  URI 1132 - Múltiplos de 13
//
//        Version:  1.0
//        Created:  09/30/2012 03:16:21 PM
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
    int n1, n2, max, min;
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
    int sum = 0;
    for (int i = min; i <= max; i++)
        if (i % 13)
            sum += i;
    printf("%d\n", sum);
    return 0;
}
