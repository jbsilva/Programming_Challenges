// ============================================================================
//
//       Filename:  01379-mean_median_problem.cpp
//
//    Description:  URI 1379 - Mean Median Problem
//
//        Version:  1.0
//        Created:  03/May/2013 19:52:13
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


#define min(a,b) (((a) < (b)) ? (a) : (b))


int main()
{
    int a, b;

    while (scanf("%d %d", &a, &b) && (a || b))
        printf("%d\n", 3 * min(a,b) - a - b);

    return 0;
}

