// ============================================================================
//
//       Filename:  hailstone_sequences.cpp
//
//    Description:  ICPC Latin American Regional - Warmup - 2011
//
//        Version:  1.0
//        Created:  29/May/2013 14:14:29
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
    unsigned n;
    while (scanf("%u", &n) && n)
    {
        unsigned maior = n;
        while (n != 1)
        {
            if (n % 2)
                n = 3 * n + 1;
            else
                n /= 2;
            if (n > maior)
                maior = n;
        }
        printf("%u\n", maior);
    }
    return 0;
}

