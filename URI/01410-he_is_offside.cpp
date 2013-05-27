// ============================================================================
//
//       Filename:  01410-he_is_offside.cpp
//
//    Description:  URI 1410 - He is Offside!
//
//                  ACM/ICPC South America Contest 2007.
//
//        Version:  1.0
//        Created:  27/May/2013 12:19:49
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

#define INF 0x3f3f3f3f

int main()
{
    int A, D;
    while (scanf("%d %d", &A, &D) && (A || D))
    {
        int min_atk = INF;
        for (int i = 0; i < A; i++)
        {
            int atk;
            scanf("%d", &atk);
            if (atk < min_atk) min_atk = atk;
        }

        int min_def = INF, min2_def = INF;
        for (int i = 0; i < D; i++)
        {
            int def;
            scanf("%d", &def);
            if (def < min_def)
            {
                min2_def = min_def;
                min_def = def;
            }
            else if (def < min2_def)
                min2_def = def;
        }
        puts((min_atk < min2_def ? "Y" : "N"));
    }
    return 0;
}

