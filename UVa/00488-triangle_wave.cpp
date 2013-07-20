// ============================================================================
//
//       Filename:  00488-triangle_wave.cpp
//
//    Description:  UVa 488 - Triangle Wave
//
//        Version:  1.0
//        Created:  19/Jul/2013 14:51:38
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
    int cases, amp, freq;

    scanf("%d", &cases);

    while (cases--)
    {
        scanf("%d %d", &amp, &freq);

        for (int i = 0; i < freq; i++)
        {
            if (i)
                putchar('\n');

            for (int j = 1; j <= amp; j++)
            {
                for (int k = 1; k <= j; k++)
                    printf("%d", j);
                putchar('\n');
            }

            for (int j = amp-1; j >= 1; j--)
            {
                for (int k = 1; k <= j; k++)
                    printf("%d", j);
                putchar('\n');
            }
        }

        if (cases)
            putchar('\n');
    }

    return 0;
}

