// ============================================================================
//
//       Filename:  11172-relational_operator.cpp
//
//    Description:  UVa 11172 - Relational Operator
//
//        Version:  1.0
//        Created:  09/Jul/2013 07:41:26
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
    int t, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &a, &b);
        if (a < b)
            puts("<");
        else if (a > b)
            puts(">");
        else
            puts("=");
    }
    return 0;
}

