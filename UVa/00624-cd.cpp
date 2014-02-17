// ============================================================================
//
//       Filename:  00624-cd.cpp
//
//    Description:  UVa 624 - CD
//
//                  Tem como resolver de formas mais eficientes.
//
//        Version:  1.0
//        Created:  17/Feb/2014 18:13:25
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int tape_len, qtd_tracks, tracks[21], MAX;
bool ans[21];


int backtrack(int k, bool mask[])
{
    int max;
    if (k < qtd_tracks)
    {
        bool mask0[20], mask1[20];
        for (int i = 0; i < k; i++)
            mask0[i] = mask1[i] = mask[i];
        mask0[k] = 0;
        mask1[k] = 1;
        int sum0 = backtrack(k + 1, mask0);
        int sum1 = backtrack(k + 1, mask1);
        max = sum0 > sum1 ? sum0 : sum1;
    }
    else
    {
        max = 0;
        for (int i = 0; i < qtd_tracks; i++)
            if (mask[i])
                max += tracks[i];
        if (max > tape_len)
            return 0;
        if (max > MAX)
        {
            MAX = max;
            memcpy(ans, mask, qtd_tracks);
        }
    }
    return max;
}


int main()
{
    bool mask[20];
    while (scanf("%d %d", &tape_len, &qtd_tracks) != EOF)
    {
        for (int i = 0; i < qtd_tracks; i++)
            scanf("%d", &tracks[i]);
        MAX = 0;
        int sum = backtrack(0, mask);
        for (int i = 0; i < qtd_tracks; i++)
            if (ans[i])
                printf("%d ", tracks[i]);
        printf("sum:%d\n", sum);
    }
    return 0;
}

