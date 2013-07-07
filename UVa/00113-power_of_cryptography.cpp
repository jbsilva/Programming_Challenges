// ============================================================================
//
//       Filename:  00113-power_of_cryptography.cpp
//
//    Description:  UVa 113 - Power of Cryptography
//
//        Version:  1.0
//        Created:  06/Jul/2013 21:09:13
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>


int main()
{
    double p;
    int n;

    while (scanf("%d %lf", &n, &p) != EOF)
        printf("%.0f\n", pow(p, 1.0/n));

    return 0;
}

