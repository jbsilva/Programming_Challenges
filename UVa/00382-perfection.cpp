// ============================================================================
//
//       Filename:  00382-perfection.cpp
//
//    Description:  UVa 382 - Perfection
//
//        Version:  1.0
//        Created:  19/Jul/2013 14:27:02
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
    int n;

    puts("PERFECTION OUTPUT");

    while (scanf("%d", &n) && n)
    {
        int sum = 0;
        for (int i = 1; i <= n/2; i++)
            if (n % i == 0)
                sum += i;

        if (sum > n)
            printf("%5d  ABUNDANT\n", n);
        else if (sum < n)
            printf("%5d  DEFICIENT\n", n);
        else
            printf("%5d  PERFECT\n", n);
    }

    puts("END OF OUTPUT");

    return 0;
}

