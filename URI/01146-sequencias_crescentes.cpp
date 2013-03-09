// ============================================================================
//
//       Filename:  01146-sequencias_crescentes.cpp
//
//    Description:  URI 1146 - Sequências Crescentes
//
//        Version:  1.0
//        Created:  09/30/2012 04:42:39 PM
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
    int x, i;
    scanf("%d", &x);
    while (x)
    {
        putchar('1');
        for (i = 2; i <= x; i++)
            printf(" %d", i);
        putchar('\n');
        scanf("%d", &x);
    }
    return 0;
}
