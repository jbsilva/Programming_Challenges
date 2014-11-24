// ============================================================================
//
//       Filename:  d-deceitful_war.cpp
//
//    Description:  Problem D - Deceitful War
//                  Qualification Round 2014
//
//        Version:  1.0
//        Created:  12/Apr/2014 04:07:23
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    int T, N;
    double naomi[1001], ken[1001];
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        printf("Case #%d: ", caso);
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%lf", &naomi[i]);
        for (int i = 0; i < N; i++)
            scanf("%lf", &ken[i]);
        sort(naomi, naomi + N);
        sort(ken, ken + N);

        // Deceitful War
        // Quando ela for perder de qualquer forma, joga o menor bloco e faz o
        // Ken gastar o maior
        int pts = N;
        for (int i = 0, j = 0; i < N; i++)
            if (naomi[i] < ken[j])
                pts--;
            else
                j++;
        printf("%d", pts);

        // War
        pts = 0;
        for (int i = N - 1, j = N - 1; i >= 0; i--)
            if (naomi[i] > ken[j])
                pts++;
            else
                j--;
        printf(" %d\n", pts);
    }
    return 0;
}
