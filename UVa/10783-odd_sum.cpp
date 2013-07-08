// ============================================================================
//
//       Filename:  10783-odd_sum.cpp
//
//    Description:  UVa 10783 - Odd Sum
//
//                  Soma de Progressão Aritimética
//
//        Version:  1.0
//        Created:  08/Jul/2013 13:58:32
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
    int T, a, b;

    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d %d", &a, &b);

        if (a % 2 == 0) a++;
        if (b % 2 == 0) b--;

        printf("Case %d: %d\n", caso, (b - a + 2) * (a + b) / 4);
    }

    return 0;
}

