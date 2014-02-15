// ============================================================================
//
//       Filename:  11661-burger_time.cpp
//
//    Description:  UVa 11661 - Burger Time
//
//        Version:  1.0
//        Created:  15/Feb/2014 13:31:26
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


const int INF = 0x3f3f3f;


inline int dif(int a, int b)
{
    return a > b ? a - b : b - a;
}


int main()
{
    int L;
    char h[2000001];
    while (scanf("%d ", &L) && L)
    {
        gets(h);
        int ur = INF, ud = INF, dist = INF, dist_a;
        for (int i = 0; i < L; i++)
        {
            if (h[i] == 'Z')
            {
                dist = 0;
                break;
            }
            else if (h[i] == 'R')
            {
                ur = i;
                if ((dist_a = dif(ur, ud)) < dist)
                    dist = dist_a;
            }
            else if (h[i] == 'D')
            {
                ud = i;
                if ((dist_a = dif(ur, ud)) < dist)
                    dist = dist_a;
            }
        }
        printf("%d\n", dist);
    }
    return 0;
}

