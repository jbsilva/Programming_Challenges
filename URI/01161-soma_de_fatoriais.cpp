// ============================================================================
//
//       Filename:  01161-soma_de_fatoriais.cpp
//
//    Description:  URI 1161 - Soma de Fatoriais
//
//        Version:  1.0
//        Created:  10/Oct/2012 21:45:40
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

typedef unsigned long long int ULLI;

int main()
{
    ULLI f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
                479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
                355687428096000, 6402373705728000, 121645100408832000,
                2432902008176640000
               };
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
        printf("%llu\n", f[m] + f[n]);
    return 0;
}
