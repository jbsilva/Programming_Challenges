// ============================================================================
//
//       Filename:  01081-dfsr_profundidade_com_hierarquia.cpp
//
//    Description:  URI 1081 - DFSr - Profundidade com Hierarquia
//
//                  O enunciado não deixa claro o tamanho máximo do grafo, mas
//                  ele sugere usar matriz de adjacência (e não lista),
//                  portanto assumo que não seja grande. Assim rodou em 0.000s.
//
//        Version:  1.0
//        Created:  12/Feb/2013 21:32:35
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

bool adj[500][500];
int lbl[500];
int qtd_v, qtd_a;
bool tinha_aresta = true;


void dfs(int v)
{
    for (int w = 0; w < qtd_v; w++)
        if (adj[v][w])
        {
            tinha_aresta = true;
            for (int i = 0; i <= lbl[v]; i++) printf("  ");
            printf("%d-%d", v, w);
            if (lbl[w] == -1)
            {
                printf(" pathR(G,%d)\n", w);
                lbl[w] = lbl[v] + 1;
                dfs(w);
            }
            else
                putchar('\n');
        }
}


int main()
{
    int cases;
    scanf("%d", &cases);
    for (int caso = 1; caso <= cases; caso++)
    {
        memset(adj, 0, sizeof(adj));
        memset(lbl, -1, sizeof(lbl));
        scanf("%d %d", &qtd_v, &qtd_a);
        int v1, v2;
        for (int a = 0; a < qtd_a; a++)
        {
            scanf("%d %d", &v1, &v2);
            adj[v1][v2] = 1;
        }
        printf("Caso %d:\n", caso);
        for (int v = 0; v < qtd_v; v++)
            if (lbl[v] == -1)
            {
                lbl[v] = 0;
                tinha_aresta = false;
                dfs(v);
                if (tinha_aresta)
                    putchar('\n');
            }
    }
    return 0;
}

