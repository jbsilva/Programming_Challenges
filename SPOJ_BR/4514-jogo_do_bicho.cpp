// ============================================================================
//
//       Filename:  4514-jogo_do_bicho.cpp
//
//    Description:  Jogo do Bicho
//                  Primeira fase da Maratona de Programação - 2005
//                  br.spoj.pl/problems/BICHO/
//
//        Version:  1.0
//        Created:  09/16/2012 11:56:15 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    // Hash table
    int grupo[100];
    grupo[0] = 24;
    for (int i = 1; i < 100; i++)
        grupo[i] = (i - 1) / 4;
    double valor;
    int aposta, sorteado;
    while (cin >> valor >> aposta >> sorteado && (valor || aposta || sorteado))
    {
        if (aposta % 10000 == sorteado % 10000)
            cout << valor * 3000 << endl;
        else if (aposta % 1000 == sorteado % 1000)
            cout << valor * 500 << endl;
        else if (aposta % 100 == sorteado % 100)
            cout << valor * 50 << endl;
        else if (grupo[aposta % 100] == grupo[sorteado % 100])
            cout << valor * 16 << endl;
        else
            cout << "0.00" << endl;
    }
    return 0;
}
