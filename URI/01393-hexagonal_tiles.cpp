// ============================================================================
//
//       Filename:  01393-hexagonal_tiles.cpp
//
//    Description:  URI 1393 - Hexagonal Tiles
//
//                  É um simples Fibonacci
//
//        Version:  1.0
//        Created:  14/Jul/2013 21:16:35
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int fib[50], n;

    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 40; i++)
        fib[i] = fib[i-2] + fib[i-1];

    while (scanf("%d", &n) && n)
        printf("%d\n", fib[n]);

    return 0;
}

