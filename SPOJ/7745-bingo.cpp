// ============================================================================
// 
//       Filename:  7745-bingo.cpp (SPOJ)
//                  12239-Bingo.cpp (UVa)
//                  01136-Bingo.cpp (URI)
//
//    Description:  ACM ICPC 2010 – Latin American Regional
//                  http://www.spoj.com/problems/MBINGO/
// 
//        Version:  1.0
//        Created:  03/Feb/2013 21:02:23
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int N, B, balls[91];
    set<int> diffs;

    while (scanf("%d %d", &N, &B) && N)
    {
        for (int i = 0; i < B; i++)
            scanf("%d", &balls[i]);

        sort(&balls[0], &balls[B]);

        for (int i = B-1; i > 0; i--)
            for (int j = 0; j < i; j++)
            {
                diffs.insert(balls[i] - balls[j]);

                // N e não N-1, pois o loop não gera o 0.
                if ((int)diffs.size() == N)
                {
                    puts("Y");
                    goto FIM;
                }
            }

        // Se chegou aqui é porque não deu
        puts("N");

        FIM:
        diffs.clear();
    }

    return 0;
}

