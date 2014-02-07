// ============================================================================
//
//       Filename:  10346-peters_smokes.cpp
//
//    Description:  UVa 10346 - Peter's Smokes
//
//        Version:  1.0
//        Created:  07/Feb/2014 16:42:03
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
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF)
    {
        int total = n;
        while (n >= k)
        {
            int butts = n % k;
            n /= k;
            total += n;
            n += butts;
        }
        printf("%d\n", total);
    }
    return 0;
}

