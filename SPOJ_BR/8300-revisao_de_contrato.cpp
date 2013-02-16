// ============================================================================
// 
//       Filename:  8300-revisao_de_contrato.cpp (SPOJ BR)
//                  01120-revisao_de_contrato.cpp (URI)
// 
//    Description:  SPOJ BR 8300 - Revisão de contrato
//                  Resolvido durante o primeiro simulado do grupo do Facebook
// 
//        Version:  1.0
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
        bool imprimiu = false;
        for (i=0; i<n.length(); i++)
        {
            bool imprimir_zero = false;
            if (n.at(i) != d)
            {
                if (n.at(i) != '0' && n.at(i) != d)
                    imprimir_zero = true;

                if (i==n.length()-1 && n.at(i) == '0')
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

