// ============================================================================
//
//       Filename:  01153-fatorial_simples.cpp
//
//    Description:  URI 1153 - Fatorial Simples
//
//        Version:  1.0
//        Created:  09/30/2012 08:32:08 PM
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
    unsigned int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800,
                        39916800, 479001600
                       };
    int n;
    scanf("%d", &n);
    printf("%u\n", f[n]);
    return 0;
}
