// ============================================================================
//
//       Filename:  a-magic_trick.cpp
//
//    Description:  Problem A - Magic Trick
//                  Qualification Round 2014
//
//        Version:  1.0
//        Created:  12/Apr/2014 01:07:14
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
    int m[4][4], T, lin, possib[17];

    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        memset(possib, 0, sizeof(possib));

        scanf("%d", &lin);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &m[i][j]);

        for (int j = 0; j < 4; j++)
            possib[m[lin-1][j]]++;

        scanf("%d", &lin);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                scanf("%d", &m[i][j]);

        for (int j = 0; j < 4; j++)
            possib[m[lin-1][j]]++;

        int ans = 0;
        bool bad = false;
        for (int i = 0; i < 4 && !bad; i++)
        {
            if (possib[m[lin-1][i]] == 2)
            {
                if (!ans)
                    ans = m[lin-1][i];
                else
                    bad = true;
            }
        }

        printf("Case #%d: ", caso);
        if (bad)
            puts("Bad magician!");
        else if (ans)
            printf("%d\n", ans);
        else
            puts("Volunteer cheated!");
    }
    return 0;
}

