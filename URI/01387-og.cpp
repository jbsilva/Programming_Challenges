// ============================================================================
//
//       Filename:  01387-og.cpp
//
//    Description:  URI 1387 - Og
//
//        Version:  1.0
//        Created:  10/May/2013 19:54:20
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
    int L, R;
    while (scanf("%d %d", &L, &R) && (L || R))
        printf("%d\n", L + R);

    return 0;
}

