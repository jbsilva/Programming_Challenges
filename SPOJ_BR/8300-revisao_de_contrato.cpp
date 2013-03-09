// ============================================================================
//
//       Filename:  8300-revisao_de_contrato.cpp (SPOJ BR)
//                  11830-contract_revision.cpp (UVa)
//                  01120-revisao_de_contrato.cpp (URI)
//
//    Description:  SPOJ BR 8300 - Revisão de contrato
//                  UVa 11830 - Contract Revision
//                  URI 1120 - Revisão de contrato
//
//                  Primeira fase da Maratona de Programação - 2010
//                  Resolvido durante o primeiro simulado do grupo do Facebook
//
//                  Estranhamente, um código errado (Version 1.0) passou no
//                  SPOJ e no UVa.
//
//        Version:  2.0
//        Created:  08/12/2012 03:01:38 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char d;
    string n;
    int i;
    while (cin >> d >> n && d != '0')
    {
        bool imprimiu = false, imprimir_zero = false;
        for (i = 0; i < (int)n.length(); i++)
        {
            if (n.at(i) != d)
            {
                if (n.at(i) != '0' && n.at(i) != d)
                    imprimir_zero = true;
                // Se o último caractere é zero, imprima o zero
                if (i == (int)n.length() - 1 && n.at(i) == '0')
                    imprimir_zero = true;
                if (n.at(i) != '0')
                {
                    cout << n.at(i);
                    imprimiu = true;
                }
                else
                {
                    if (imprimir_zero)
                    {
                        cout << "0";
                        imprimiu = true;
                    }
                }
            }
        }
        if (!imprimiu)
            cout << "0";
        cout << endl;
    }
    return 0;
}

