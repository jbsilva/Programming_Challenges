// ============================================================================
//
//       Filename:  01310-profit.cpp
//
//    Description:  URI 1310 - Profit
//                  
//                  Este é o "Maximum Subarray Problem"
//                  resolvido em O(n) com o Kadane's Algorithm.
//
//        Version:  1.0
//        Created:  12/Apr/2013 16:21:04
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


inline int max(int a, int b)
{
    return a > b ? a : b;
}


int main()
{
    int days, diaria, revenue[51];

    while (scanf("%d", &days) != EOF)
    {
        scanf("%d", &diaria);

        for (int i = 0; i < days; i++)
        {
            scanf("%d", &revenue[i]);
            revenue[i] -= diaria;
        }

        int max_ending_here = 0, max_so_far = 0;
        for (int i = 0; i < days; i++)
        {
            max_ending_here = max(0, max_ending_here + revenue[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }

        printf ("%d\n", max_so_far);
    }

    return 0;
}

