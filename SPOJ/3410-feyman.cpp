// ============================================================================
//
//       Filename:  3410-feyman.cpp (SPOJ)
//                  12149-feyman.cpp (UVa)
//                  01323-feyman.cpp (URI)
//
//    Description:  SPOJ 3410 - Feyman
//                  UVa 12149 - Feyman
//                  URI 1323 - Feyman
//
//                  spoj.com/problems/SAMER08F/
//                  ACM/ICPC South America Contest 2008.
//
//        Version:  1.0
//        Created:  23/Apr/2013 13:19:52
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
    int ans[101], n;

    ans[0] = 0;
    for (int i = 1; i <= 100; i++)
        ans[i] = ans[i-1] + i*i;

    while (scanf("%d", &n) && n)
        printf("%d\n", ans[n]);

    return 0;
}

