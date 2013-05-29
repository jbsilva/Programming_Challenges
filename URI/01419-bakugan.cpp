// ============================================================================
//
//       Filename:  01419-bakugan.cpp
//
//    Description:  URI 1419 - Bakugan
//
//        Version:  1.0
//        Created:  28/May/2013 21:25:00
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

#define INF 100

int main()
{
    int R, M[11], L[11];
    while (scanf("%d", &R) && R)
    {
        for (int i = 0; i < R; i++)
            scanf("%d", &M[i]);
        for (int i = 0; i < R; i++)
            scanf("%d", &L[i]);

        int m_extr = INF, m_pts = 0;
        for (int i = 0; i < R; i++)
        {
            m_pts += M[i];
            if (i >= 2 && m_extr == INF && (M[i] == M[i - 1]) && (M[i] == M[i - 2]))
                m_extr = i;
        }

        int l_extr = INF, l_pts = 0;
        for (int i = 0; i < R; i++)
        {
            l_pts += L[i];
            if (i >= 2 && l_extr == INF && (L[i] == L[i - 1]) && (L[i] == L[i - 2]))
                l_extr = i;
        }

        if (m_extr < l_extr)
            m_pts += 30;
        else if (l_extr < m_extr)
            l_pts += 30;

        if (m_pts > l_pts)
            puts("M");
        else if (l_pts > m_pts)
            puts("L");
        else
            puts("T");
    }
    return 0;
}

