// ============================================================================
//
//       Filename:  10079-pizza_cutting.cpp
//
//    Description:  UVa 10079 - Pizza Cutting
//                  Soma de PA
//
//        Version:  1.0
//        Created:  31/Jul/2013 00:32:06
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int main()
{
    int n;
    while (scanf("%d", &n) && n > 0)
        printf("%d\n", 1 + ((1 + n) * n/2));

    return 0;
}
