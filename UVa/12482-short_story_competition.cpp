// ===================================================================
// 
//       Filename:  12482-short_story_competition.cpp
// 
//    Description:  Problema A: Concurso de Contos
//                  Primeira Fase da Maratona de Programação 2012
// 
//        Version:  1.0
//        Created:  09/17/2012 04:52:15 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ===================================================================
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int qtd_palavras, max_lin, max_char;
    while (cin >> qtd_palavras >> max_lin >> max_char)
    {
        string p;
        int tam = 0, qtd_linhas = 0;
        for (int i=0; i < qtd_palavras; i++)
        {
            cin >> p;

            tam += p.length() + 1;

            if (tam > max_char+1)
            {
                qtd_linhas++;
                tam = p.length() + 1;
            }
            
            if (tam == max_char || tam-1 == max_char)
            {
                qtd_linhas++;
                tam = 0;
            }
            else if (i == qtd_palavras-1)
                qtd_linhas++;
        }

        // O cast para double é fundamental. Perdemos tempo debugando durante a
        // maratona
        cout << ceil((double)qtd_linhas/max_lin) << endl;
    }
    return 0;
}
