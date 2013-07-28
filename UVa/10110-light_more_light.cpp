// ============================================================================
//
//       Filename:  10110-light_more_light.cpp
//
//    Description:  UVa 10110 - Light, more light
//                  Verificar se n é quadrado perfeito
//
//        Version:  1.0
//        Created:  27/Jul/2013 12:25:16
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
    unsigned int n;
    while (scanf("%u", &n) && n)
    {
        unsigned int s = (unsigned int)sqrt(n);
        puts(s*s == n ? "yes" : "no");
    }
    return 0;
}

