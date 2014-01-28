// ============================================================================
//
//       Filename:  11847-cut_the_silver_bar.cpp
//
//    Description:  UVa 11847 - Cut The Silver Bar
//
//        Version:  1.0
//        Created:  25/Jan/2014 18:09:11
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
    int n;
    while (scanf("%d", &n) && n)
        printf("%d\n", (int)log2(n));
    return 0;
}

