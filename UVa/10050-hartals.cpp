// ============================================================================
//
//       Filename:  10050-hartals.cpp
//
//    Description:  UVa 10050 - Hartals
//
//        Version:  1.0
//        Created:  20/Jul/2013 22:24:17
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
    int T, N, P;
    bool dias[4000];

    scanf("%d", &T);
    while (T--)
    {
        memset(dias, 0, sizeof(dias));

        scanf("%d %d", &N, &P);

        int soma = 0;
        for (int i = 0; i < P; i++)
        {
            int h;
            scanf("%d", &h);

            for (int j = h-1; j < N; j += h)
                if (j % 7 != 5 && j % 7 != 6)
                    if (!dias[j])
                    {
                        dias[j] = 1;
                        soma++;
                    }
        }

        printf("%d\n", soma);
    }
    return 0;
}

