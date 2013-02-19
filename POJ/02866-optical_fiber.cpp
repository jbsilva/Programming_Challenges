// ============================================================================
// 
//       Filename:  02866-optical_fiber.cpp (POJ)
//                  01270-optical_fiber.cpp (URI)
// 
//    Description:  ACM/ICPC South America Contest 2005
//                  POJ 2866 - Optical Fiber
//                  URI 1270 - Optical Fiber
// 
//        Version:  1.0
//        Created:  18/Feb/2013 22:11:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//                  Agradecimentos ao Alexandre Marin
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
using namespace std;

#define NN 1001   // Quantidade máxima de cidades
#define CC 51     // Quantidade máxima de locais candidatos
#define INF 1E100 // Infinito

int adj[NN][NN]; // Essa matriz de adj. funciona como uma lista de adjacência
int grau[NN], c[NN];
int x[NN][CC], y[NN][CC];
bool visitado[NN];
double custo[NN][CC];
map<string, int> id; // Permite acessar o ID de uma cidade em O(log(n))


void dfs(int v)
{
    visitado[v] = 1;

    for (int i = 0; i < grau[v]; i++)
    {
        int u = adj[v][i];

        if (!visitado[u])
        {
            dfs(u);
            for (int j = 0; j < c[v]; j++)
            {
                double d, min = INF;
                for (int k = 0; k < c[u]; k++)
                {
                    d = hypot(x[v][j]-x[u][k], y[v][j]-y[u][k]) + custo[u][k];

                    if (d < min)
                        min = d;
                }
                custo[v][j] += min;
            }
        }
    }
}


int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        id.clear();
        memset(grau, 0, n*sizeof(int));
        memset(visitado, 0, n*sizeof(int));
        memset(custo, 0, sizeof(custo));

        for (int i = 0; i < n; i++)
        {
            char cidade[16];
            scanf("%s %d", cidade, &c[i]);
            id[string(cidade)] = i;

            for (int j = 0; j < c[i]; j++)
                scanf("%d %d", &x[i][j], &y[i][j]);
        }

        for (int i = 1; i < n; i++)
        {
            char c1_nome[16], c2_nome[16];
            scanf("%s %s", c1_nome, c2_nome);

            int id1 = id[string(c1_nome)];
            int id2 = id[string(c2_nome)];

            adj[id1][grau[id1]++] = id2;
            adj[id2][grau[id2]++] = id1;
        }

        dfs(0);
        double min = INF;
        for (int i = 0; i < c[0]; i++)
            if (custo[0][i] < min)
                min = custo[0][i];

        printf("%.1lf\n", min);
    }

    return 0;
}

