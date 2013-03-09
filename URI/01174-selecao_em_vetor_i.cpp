// ============================================================================
//
//       Filename:  01174-selecao_em_vetor_i.cpp
//
//    Description:  URI 1174 - Seleção em Vetor I
//
//        Version:  1.0
//        Created:  09/28/2012 04:51:40 PM
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
    double n;
    for (int i = 0; i < 100; i++)
    {
        cin >> n;
        if (n <= 10)
            cout << "A[" << i << "] = " << n << endl;
    }
    return 0;
}
