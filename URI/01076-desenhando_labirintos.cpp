// ============================================================================
//
//       Filename:  01076-desenhando_labirintos.cpp
//
//    Description:  URI 1076 - Desenhando Labirintos
//
//                  Este problema lembra o Travelling Salesman Problem (TSP),
//                  que é NP-hard. Mas temos no máximo 7x7 = 49 nós de tamanho
//                  igual a 1 e o grafo é uma árvore.
//
//        Version:  1.0
//        Created:  24/May/2013 11:41:38
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


typedef vector<int> vi;
vector<vi> AdjList;
bool visitado[50];
int arestas;


void dfs(int n)
{
    visitado[n] = 1;
    for (vi::iterator it = AdjList[n].begin(); it != AdjList[n].end(); ++it)
        if (!visitado[*it])
        {
            arestas++;
            dfs(*it);
        }
}


int main()
{
    int T, N, V, A;
    scanf("%d", &T);
    while (T--)
    {
        memset(visitado, 0, sizeof(visitado));
        arestas = 0;
        scanf("%d %d %d", &N, &V, &A);
        AdjList.assign(V, vi());
        for (int i = 0; i < A; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            AdjList[u].push_back(v);
            AdjList[v].push_back(u);
        }
        dfs(N);
        printf("%d\n", 2 * arestas);
    }
    return 0;
}

