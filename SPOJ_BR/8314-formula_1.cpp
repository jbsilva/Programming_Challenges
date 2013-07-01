// ============================================================================
//
//       Filename:  8314-formula_1.cpp (SPOJ BR)
//                  11835-formula_1.cpp (UVa)
//                  01125-formula_1.cpp (URI)
//
//    Description:  SPOJ BR 8314 - Fórmula 1
//                  UVa 11835 - Formula 1
//                  URI 1125 - Fórmula 1
//
//                  br.spoj.com/problems/FORMULA/
//
//        Version:  1.0
//        Created:  01/Jul/2013 18:11:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


int main()
{
    int G, P, S, K, pts[101], pts_piloto[101], pos_piloto[101][101];
    vector<int> champs;
    while (scanf("%d %d", &G, &P) && (G || P))
    {
        for (int i = 0; i < G; i++)
            for (int j = 1; j <= P; j++)
                scanf("%d", &pos_piloto[i][j]);

        scanf("%d", &S);
        while (S--)
        {
            memset(pts, 0, sizeof(pts));
            memset(pts_piloto, 0, sizeof(pts_piloto));

            scanf("%d", &K);
            for (int i = 1; i <= K; i++)
                scanf("%d", &pts[i]);

            for (int i = 0; i < G; i++)
                for (int j = 1; j <= P; j++)
                    pts_piloto[j] += pts[pos_piloto[i][j]];

            int max = 0;
            for (int i = 1; i <= P; i++)
                if (pts_piloto[i] > max)
                    max = pts_piloto[i];
            for (int i = 1; i <= P; i++)
                if (pts_piloto[i] == max)
                    champs.push_back(i);

            vector<int>::iterator it = champs.begin();
            printf("%d", *it);
            for (++it; it != champs.end(); ++it)
                printf(" %d", *it);
            putchar('\n');
            champs.clear();
        }
    }
    return 0;
}

