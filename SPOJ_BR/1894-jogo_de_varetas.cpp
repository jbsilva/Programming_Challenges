// ============================================================================
//
//       Filename:  1894-jogo_de_varetas.cpp
//
//    Description:  br.spoj.pl/problems/VARETAS/
//                  Primeira fase da Maratona de Programação - 2007
//
//        Version:  1.0
//        Created:  09/13/2012 10:03:47 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
using namespace std;

int main()
{
    int n; // número de diferentes comprimentos
    while (cin >> n && n)
    {
        int soma_pares = 0;
        for (int i = 0; i < n; i++)
        {
            int tam, qtd;
            cin >> tam >> qtd;
            soma_pares += qtd / 2;
        }
        cout << soma_pares / 2 << endl;
    }
    return 0;
}
