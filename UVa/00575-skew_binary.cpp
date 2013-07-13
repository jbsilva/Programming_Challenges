// ============================================================================
//
//       Filename:  00575-skew_binary.cpp
//
//    Description:  UVa 575 - Skew Binary
//
//        Version:  1.0
//        Created:  12/Jul/2013 21:09:06
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cmath>


int main()
{
    char n[70];
    while (scanf("%s", n) && !(n[0] == '0' && n[1] == '\0'))
    {
        int tam = strlen(n);
        int dec = 0;
        for (int i = tam - 1, k = 1; i >= 0; i--, k++)
            dec += (int)(n[i] - '0') * (pow(2, k) - 1);
        printf("%d\n", dec);
    }
    return 0;
}

