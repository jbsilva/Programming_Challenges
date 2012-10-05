// ============================================================================
// 
//       Filename:  01205-cerco_a_leningrado.cpp
// 
//    Description:  URI 1205 - Cerco a Leningrado
//
//                  Problema D (Seletiva IME-USP): Cerco a Leningrado
//                  É um problema de caminho mínimo em um dígrafo com pesos não
//                  negativos. A quantidade de soldados em cada vértice é
//                  atribuída a todas as arestas chegando naquele vértice.
//                  Você também precisa matar os soldados na origem e destino.
//
//        Version:  1.0
//        Created:  08/18/2012 05:08:23 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

#define DEBUG 0

const int INF = 0x3f3f3f3f;
// Quantidade máxima de vertices
const int MAXV = 1001;
// Matriz de distâncias
int grafo[MAXV][MAXV];

int dijkstra(int origem, int destino, int v)
{
    int i,minimo,atual;
    int pred[MAXV], passou[MAXV], custo[MAXV];

    for(i=0;i<v;i++)
    {
        pred[i] = -1;
        passou[i] = 0;
        custo[i] = INF;
    }

    custo[origem] = 0;
    atual = origem;

    while(atual != destino)
    {
        for (i=0; i<v; i++)
            if (grafo[atual][i] != -1)
                if (custo[atual] + grafo[atual][i] < custo[i])
                {
                    custo[i] = custo[atual] + grafo[atual][i];
                    pred[i] = atual;
                }

        minimo = INF + 1;
        passou[atual] = 1;
        for (i=0; i<v; i++)
            if((custo[i] < minimo) && (!passou[i]))
            {
                minimo = custo[i];
                atual = i;
            }

        if (minimo >= INF)
            return INF;
    }

    return custo[destino];
}


int main()
{
    int vertices, arestas, balas, atiradores, origem, destino;
    double prob;

    while (cin >> vertices >> arestas >> balas >> prob)
    {
        // 0xff = -1. Indica que não existe aresta ligando i com j
        memset(grafo, 0xff, sizeof(grafo));

        // Preenche diagonal com 0s. Dist(v,v)=0
        for (int i=0; i<MAXV; i++)
            grafo[i][i] = 0;

        while (arestas--)
        {
            int a, b;
            cin >> a >> b;
            grafo[a-1][b-1] = 0; // tem aresta ab. -1, pois inicia do 0
            grafo[b-1][a-1] = 0; // tem aresta ba. -1, pois inicia do 0
        }

        cin >> atiradores;

        // # de atiradores por vértice. Útil para saber a qtd na origem
        int atirads[1000];
        memset(atirads, 0, sizeof(atirads));

        for (int i=0; i<atiradores; i++)
        {
            int v;
            cin >> v;

            atirads[v-1]++;

            // Preenche coluna
            for (int j=0; j<vertices; j++)
                if (j != v-1 && grafo[j][v-1] != -1)
                    grafo[j][v-1]++;
        }

#if DEBUG
        cout << endl << "########## GRAFO ##########" << endl;
        for (int i=0; i<vertices; i++)
        {
            for (int j=0; j<vertices; j++)
                cout << grafo[i][j] << " ";
            cout << endl;
        }
#endif

        cin >> origem >> destino;

        // Atiradores no caminho
        atiradores = atirads[origem-1] + dijkstra(origem-1, destino-1, vertices);

        if (balas < atiradores)
            cout << "0.000" << endl;
        else
            cout << fixed << setprecision(3) << pow(prob,atiradores) << endl;
    }

    return 0;
}
