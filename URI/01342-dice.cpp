// ============================================================================
//
//       Filename:  01342-dice.cpp
//
//    Description:  URI 1342 - Dice
//
//        Version:  1.0
//        Created:  28/Apr/2013 21:36:50
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
    int P, S, N, t[3], d1, d2, pos[11], plyr; // N=Dice rolls, t=traps
    bool trapped[11];

    while (scanf("%d %d", &P, &S) && (P || S))
    {
        memset(trapped, 0, sizeof(trapped));
        memset(pos, 0, sizeof(pos));

        scanf("%d %d %d %d", &t[0], &t[1], &t[2], &N);

        plyr = -1;
        for (int i = 0; i < N; i++)
        {
            plyr = (plyr+1) % P;
            while (trapped[plyr])
            {
                trapped[plyr] = false;
                plyr = (plyr+1) % P;
            }

            scanf("%d %d", &d1, &d2);
            pos[plyr] += d1+d2;

            if (pos[plyr] == t[0] || pos[plyr] == t[1] || pos[plyr] == t[2])
                trapped[plyr] = true;
        }

        printf("%d\n", plyr+1);
    }

    return 0;
}

