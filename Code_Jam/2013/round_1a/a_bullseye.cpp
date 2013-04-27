// ============================================================================
//
//       Filename:  a_bullseye.cpp
//
//    Description:  Problem A - Bullseye
//
//        Version:  1.0
//        Created:  26/Apr/2013 22:05:01
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
    int T, rings;
    long double r, tinta;

    scanf("%d", &T);

    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%Lf %Lf", &r, &tinta);

        rings = 0;
        while (42)
        {
            tinta -= 2.0 * r + 1.0;
            if (tinta < 0) break;
            rings++;
            r += 2.0;
        }

        printf("Case #%d: %d\n", caso, rings);
    }

    return 0;
}

