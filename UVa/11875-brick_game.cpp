// ============================================================================
//
//       Filename:  11875-brick_game.cpp
//
//    Description:  UVa 11875 - Brick Game
//
//        Version:  1.0
//        Created:  07/Feb/2014 16:25:07
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
    int T, n, v[11];
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        printf("Case %d: %d\n", caso, v[n / 2]);
    }
    return 0;
}

