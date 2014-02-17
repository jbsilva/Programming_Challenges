// ============================================================================
//
//       Filename:  11659-informants.cpp
//
//    Description:  UVa 11659 - Informants
//
//                  2-SAT, Backtrack
//
//        Version:  1.0
//        Created:  15/Feb/2014 16:23:55
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int t[21][21], v[21], infs, ans;


int backtrack(int n, int *r)
{
    int r1[21], r2[21], maior;
    if (n <= infs)
    {
        for (int i = 1; i <= infs; i++)
            r1[i] = r2[i] = r[i];
        r1[n] = 1;
        r2[n] = -1;
        int v_r1 = backtrack(n + 1, r1);
        int v_r2 = backtrack(n + 1, r2);
        maior = v_r1 > v_r2 ? v_r1 : v_r2;
    }
    else
    {
        // Verifica contradição
        for (int i = 1; i <= infs; i++)
            if (r[i] == 1)
                for (int j = 1; j <= infs; j++)
                    if (t[i][j] * r[j] == -1)
                        return 0;
        maior = 0;
        for (int i = 1; i <= infs; i++)
            if (r[i] == 1)
                maior++;
    }
    return maior;
}


int main()
{
    while (scanf("%d %d", &infs, &ans) && (infs || ans))
    {
        memset(v, 0, sizeof(v));
        memset(t, 0, sizeof(t));
        if (ans)
        {
            while (ans--)
            {
                int x, y;
                scanf("%d %d", &x, &y);
                if (y < 0)
                    t[x][-y] = -1;
                else
                    t[x][y] = 1;
            }
            printf("%d\n", backtrack(1, v));
        }
        else
            printf("%d\n", infs);
    }
    return 0;
}

