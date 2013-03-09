// ============================================================================
//
//       Filename:  1888-rouba_monte.cpp
//
//    Description:  Primeira fase da Maratona de Programação - 2007
//                  br.spoj.pl/problems/ROUBA/
//        Version:  1.0
//        Created:  09/14/2012 01:50:48 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <set>
#include <deque>
#include <vector>
using namespace std;

#define DEBUG 0
#define dbg if(DEBUG)

int main()
{
    int compra[10001];
    int n, j; // número de cartas no baralho | número que jogadores
    while (cin >> n >> j && (n || j))
    {
        // Lê monte de compra
        for (int i = 0; i < n; i++)
            cin >> compra[i];
        // Simula jogo
        deque<int> monte[j]; // Montes de cada jogador
        set<int> descarte;
        int vez = 0; // Jogador da vez. Indexando a partir do 0
        int carta_vez = 0; // indice do vetor compra
        while (carta_vez < n)
        {
            bool passa_vez = true;
            dbg cout << "### Carta da vez: " << compra[carta_vez] << endl;
            // carta_vez estava no descarte.
            if (descarte.erase(compra[carta_vez]))
            {
                passa_vez = false;
                monte[vez].push_back(compra[carta_vez]);
                monte[vez].push_back(compra[carta_vez]);
            }
            else
            {
                bool roubou = false;
                for (int i = 0; i < j; i++)
                    if (!monte[i].empty() && monte[i].back() == compra[carta_vez])
                    {
                        passa_vez = false;
                        if (i != vez)
                        {
                            monte[vez].insert(monte[vez].end(), monte[i].begin(), monte[i].end());
                            monte[i].clear();
                        }
                        roubou = true;
                    }
                // Empilha carta_vez apenas uma vez, mesmo roubando mais de um
                if (roubou)
                    monte[vez].push_back(compra[carta_vez]);
            }
            if (passa_vez)
            {
                descarte.insert(compra[carta_vez]);
                vez = (vez + 1) % j;
            }
            carta_vez++;
        }
        vector<int> ganhadores;
        unsigned int max = 0;
        for (int i = 0; i < j; i++)
        {
            if (monte[i].size() > max)
            {
                max = monte[i].size();
                ganhadores.clear();
                ganhadores.push_back(i + 1);
            }
            else if (monte[i].size() == max)
                ganhadores.push_back(i + 1);
        }
        cout << max;
        for (vector<int>::iterator it = ganhadores.begin(); it != ganhadores.end(); it++)
            cout << " " << *it;
        cout << endl;
    }
    return 0;
}
