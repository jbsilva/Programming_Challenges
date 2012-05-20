// =====================================================================================
// 
//       Filename:  10034-freckles.cpp
// 
//    Description:  UVA 10034
//                  Devemos achar o peso da menor spanning tree.
//                  Aqui usarei uma variação do algoritmo de prim  por ser bem simples
//                  Existem soluções mais eficientes.
//
//                  Podemos usar programação dinâmina para aumentar a eficiência do algoritmo
//                  mantendo um vetor com as distâncias entre cada vértice pré calculada.
//
//        Version:  1.0
//        Created:  05/22/2011 08:48:23 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <limits>
using namespace std;

typedef unsigned short int USI;
const float INF = numeric_limits<float>::infinity();

class Vertice
{
    public:
        float X;                                        // Coordenada x
        float Y;                                        // Coordenada y

        Vertice(float x=0.0, float y=0.0)               // Construtor
            :X(x), Y(y)
        {
        }
};

// Calcula a distância entre dois vértices
float distancia(Vertice a, Vertice b)
{
    return sqrt( (a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y) );
}

int main()
{
    USI cases, qtd_vertices;
    Vertice freckle;                        // Contém as coordenadas de uma sarda
    list<Vertice> Q_disp;                   // Fila de vértices ainda não usados na árvore
    list<Vertice> Q_mst;                    // Fila de vértices já percorridos pela na árvore
    list<Vertice>::iterator it_disp;        // Iterador para fila de vértices disponíveis
    list<Vertice>::iterator it_mst;         // Iterador para fila de vértices não disponíveis
    list<Vertice>::iterator it_min;         // Marca a posição do vetor com menor distância
    float custo;                            // Comprimento total da MST
    float dist;
    float min_dist;                   
    
    cin >> cases;

    while (cases--)
    {
        // Número de sardas
        cin >> qtd_vertices;

        // Constroi uma fila com todos os vértices que não estão na árvore (MSP)
        for (USI i=0; i<qtd_vertices; i++)
        {
            cin >> freckle.X >> freckle.Y;
            Q_disp.push_back(freckle);
        }

        // Tira um vértice da fila de disponíveis e adiciona à raíz da árvore
        freckle = Q_disp.front();
        Q_disp.pop_front();
        Q_mst.push_back(freckle);

        custo = 0.0;

        // Repete o algoritmo até remover todos os vértices da fila.
        // Como o 1o já foi removido, repetimos mais (qtd_vertices - 1) vezes
        while (--qtd_vertices)
        {
            // min_dist sempre mudará de valor na 1a comparação
            min_dist = INF;

            // Verifica a distância entre cada vértice já utilizado e cada vértice disponível
            // Usa o vértice correspondente à menor distância e deleta-o da fila "Q_disp"
            for (it_mst = Q_mst.begin(); it_mst != Q_mst.end(); it_mst++)
            {
                for (it_disp = Q_disp.begin(); it_disp != Q_disp.end(); it_disp++)
                {
                    dist = distancia(*it_mst, *it_disp);

                    if (dist < min_dist)
                    {
                        min_dist = dist;
                        it_min = it_disp;
                    }
                }
            }
            
            // Adiciona o vértice com menor distância à árvore
            // Torna esse vértice indisponível e incrementa o custo
            Q_mst.push_back(*it_min);
            Q_disp.erase(it_min);
            custo += min_dist;
        }

        cout << fixed << setprecision(2) << custo << endl;

        // Apaga as filas para próxima entrada. Q_disp já deve estar vazia
        Q_mst.clear();
        Q_disp.clear();

        // Não imprime '/n' no último caso.
        if (cases)
            cout << endl;
    }

    return 0;
}
