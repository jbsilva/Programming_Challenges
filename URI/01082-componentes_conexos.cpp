// ============================================================================
//
//       Filename:  01082-componentes_conexos.cpp
//
//    Description:  URI 1082 - Componentes Conexos
//
//        Version:  2.0 - Precisava imprimir ordenado
//        Created:  02/Jun/2013 20:59:24
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
#include <algorithm>
using namespace std;


typedef vector<int> vi;
vector<vi> AdjList;
vector<char> componente;
bool visitado[30];


void dfs(int n)
{
    visitado[n] = 1;
    componente.push_back((char)(n + 'a'));
    for (vi::iterator it = AdjList[n].begin(); it != AdjList[n].end(); ++it)
        if (!visitado[*it])
            dfs(*it);
}


int main()
{
    int N, V, E;
    scanf("%d", &N);
    for (int caso = 1; caso <= N; caso++)
    {
        printf("Case #%d:\n", caso);
        scanf("%d %d", &V, &E);
        memset(visitado, 0, sizeof(visitado));
        AdjList.assign(V, vi());
        for (int i = 0; i < E; i++)
        {
            char u, v;
            scanf(" %c %c ", &v, &u);
            AdjList[(int)(u - 'a')].push_back((int)(v - 'a'));
            AdjList[(int)(v - 'a')].push_back((int)(u - 'a'));
        }

        int CC = 0;
        for (int v = 0; v < V; v++)
            if (!visitado[v])
            {
                CC++;
                dfs(v);
                sort(componente.begin(), componente.end());
                for (vector<char>::iterator it = componente.begin();
                                            it != componente.end(); ++it)
                    printf("%c,", *it);
                componente.clear();
                putchar('\n');
            }
        printf("%d connected components\n\n", CC);
    }
    return 0;
}

