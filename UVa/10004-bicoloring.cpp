// ============================================================================
//
//       Filename:  10004-bicoloring.cpp
//
//    Description:  UVa 10004 - Bicoloring
//
//        Version:  1.0
//        Created:  19/Jul/2013 16:15:35
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
#include <queue>
using namespace std;


typedef vector<int> vi;
vector<vi> AdjList;
int cor[201];


int main()
{
    int V, E;
    queue<int> q;

    while (scanf("%d", &V) && V)
    {
        memset(cor, -1, sizeof(cor));

        AdjList.assign(V, vi());
        scanf("%d", &E);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }

        // Coloca o primeiro vértice na fila
        q.push(0);
        cor[0] = 0;

        bool bipartido = true;
        while (!q.empty() && bipartido)
        {
            int u = q.front(); q.pop();

            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                int v = AdjList[u][j];

                if (cor[v] == -1)
                {
                    cor[v] = 1 - cor[u];
                    q.push(v);
                }
                else if (cor[v] == cor[u])
                {
                    bipartido = false;
                    break;
                }
            }
        }

        // Esvazia resto da fila
        while (!q.empty())
            q.pop();

        puts(bipartido ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }

    return 0;
}

