// ============================================================================
//
//       Filename:  01318-fake_tickets.cpp
//
//    Description:  URI 1318 - Fake Tickets
//                  ACM/ICPC South America Contest 2002 Warm-Up
//
//        Version:  1.0
//        Created:  24/Apr/2013 17:09:13
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
    int N, M, x, t[10001], fakes;

    while (scanf("%d %d", &N, &M) && (N || M))
    {
        memset(t, 0, sizeof(t));
        fakes = 0;

        for (int i = 0; i < M; i++)
        {
            scanf("%d", &x);
            t[x]++;
            if (t[x] == 2)
                fakes++;
        }

        printf("%d\n", fakes);
    }

    return 0;
}

