// ============================================================================
//
//       Filename:  10324-zeros_and_ones.cpp
//
//    Description:  UVa 10324 - Zeros and Ones
//
//        Version:  1.0
//        Created:  19/Jul/2013 15:40:24
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
    char lin[1000001];
    int n, caso = 0, i, j;

    while (gets(lin) != NULL)
    {
        printf("Case %d:\n", ++caso);

        scanf("%d", &n);

        while (n--)
        {
            scanf("%d %d ", &i, &j);

            int min, max;

            if (i < j)
                min = i, max = j;
            else
                min = j, max = i;

            bool yes = true;
            for (; min < max; min++)
                if (lin[min] != lin[max])
                {
                    yes = false;
                    break;
                }

            puts(yes ? "Yes" : "No");
        }
    }

    return 0;
}

