// ============================================================================
// 
//       Filename:  4888-copa_do_mundo.cpp
// 
//    Description:  br.spoj.pl/problems/COPA/
//                  Primeira fase da Maratona de Programação - 2006
//                  Problema F: Copa do Mundo
//
//                  É só resolver um sistema de duas equações com duas
//                  incógnitas.
// 
//        Version:  1.0
//        Created:  09/12/2012 03:15:20 PM
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
    int times, partidas;
    while (cin >> times >> partidas && times)
    {
        int soma_pontos = 0;
        for (int i=0; i < times; i++)
        {
            string nome; int pontos;
            cin >> nome >> pontos;
            soma_pontos += pontos;
        }

        cout << 3*partidas - soma_pontos << endl;
    }
    return 0;
}
