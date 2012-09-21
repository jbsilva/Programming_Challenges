// ============================================================================
// 
//       Filename:  5478-subprime.cpp
// 
//    Description:  Primeira Fase da Maratona de Programação - 2009
//                  br.spoj.pl/problems/SUBPRIME/
// 
//        Version:  1.0
//        Created:  09/16/2012 10:04:06 PM
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
    int bancos, deb;
    while (cin >> bancos >> deb && (bancos || deb))
    {
        int reserva[bancos];
        for (int i=0; i < bancos; i++)
            cin >> reserva[i];

        for (int i=0; i < deb; i++)
        {
            int devedor, credor, valor;
            cin >> devedor >> credor >> valor;
            reserva[devedor-1] -= valor;
            reserva[credor-1] += valor;
        }

        bool possivel = true;
        for (int i=0; i < bancos; i++)
            if (reserva[i] < 0)
            {
                possivel = false; break;
            }

        cout << (possivel?"S":"N") << endl;
    }
    return 0;
}
