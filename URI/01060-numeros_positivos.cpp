// ============================================================================
//
//       Filename:  01060-numeros_positivos.cpp
//
//    Description:  URI 1060 - Números Positivos
//
//        Version:  1.0
//        Created:  09/28/2012 08:36:05 PM
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
    int positivos = 0;
    double n;
    for (int i = 0; i < 6; i++)
    {
        cin >> n;
        if (n > 0)
            positivos++;
    }
    cout << positivos << " valores positivos" << endl;
    return 0;
}
