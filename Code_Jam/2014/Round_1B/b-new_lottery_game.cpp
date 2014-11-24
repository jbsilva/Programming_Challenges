// ============================================================================
// 
//       Filename:  b-new_lottery_game.cpp
// 
//    Description:  B - New Lottery Game
// 
//        Version:  1.0
//        Created:  03/Mai/2014 18:10:26
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>


int main()
{
    int T, A, B, K;

    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d %d %d", &A, &B, &K);

        /*
        // Bruteforce
        int cnt = 0;
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    cnt++;
        */

        int cnt = K * B;
        for (int i = K; i < A; i++)
            for (int j = 0; j < B; j++)
                if ((i & j) < K)
                    cnt++;


        printf("Case #%d: %d\n", caso, cnt);
    }
    return 0;
}
