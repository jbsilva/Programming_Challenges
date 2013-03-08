// ============================================================================
// 
//       Filename:  11631-dark_roads.cpp (UVa)
//                  01152-dark_roads.cpp (URI)
// 
//    Description:  University of Ulm Local Contest
//                  UVa 11631 - Dark Roads
//                  URI 1152 - Dark Roads
//
//                  Gera a Minimum Spanning Tree usando o algoritmo de Prim.
//                  Código baseado no livro Competitive Programming 2ed.
// 
//        Version:  1.0 -- ACC no UVa, WA no URI
//        Created:  08/Mar/2013 16:40:14
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi taken; // Indica se um vértice já foi visitado. Evita ciclos.
priority_queue<ii> pq; // Mantém as arestas ordenadas
vector<vii> AdjList;


// Adiciona o negativo para o primeiro elemento ser o menor
void process(int vtx)
{
    taken[vtx] = 1;
    for (int j = 0; j < AdjList[vtx].size(); j++)
    {
        ii v = AdjList[vtx][j];

        if (!taken[v.first])
            pq.push(ii(-v.second, -v.first));
    }
}


int main()
{
    int V, A, u, v, w, soma;

    while (scanf("%d %d", &V, &A) && (V || A))
    {
        soma = 0;
        AdjList.assign(V, vii());

        for (int i = 0; i < A; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
            soma += w;
        }

        // Prim
        taken.assign(V, 0);
        process(0);
        int mst_cost = 0;

        while (!pq.empty())
        {
            ii front = pq.top(); pq.pop();
            u = -front.second, w = -front.first; // Armazenei o oposto

             if (!taken[u])
                 mst_cost += w, process(u);
        }

        printf("%d\n", soma - mst_cost);
    }

    return 0;
}

