// ============================================================================
//
//       Filename:  11799-horror_dash.cpp
//
//    Description:  UVa 11799 - Horror Dash
//
//        Version:  1.0
//        Created:  06/Feb/2014 22:26:54
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
    int T, n;
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d", &n);
        int max = 0, c;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &c);
            if (c > max)
                max = c;
        }
        printf("Case %d: %d\n", caso, max);
    }
    return 0;
}

