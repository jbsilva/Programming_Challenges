// ============================================================================
//
//       Filename:  01070-seis_numeros_impares.cpp
//
//    Description:  URI 1070 - Seis Números Ímpares
//
//        Version:  1.0
//        Created:  09/29/2012 04:37:50 PM
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
    int x;
    cin >> x;
    int n = x % 2 ? x : x + 1;
    for (int i = 0; i < 6; i++)
    {
        cout << n << endl;
        n += 2;
    }
    return 0;
}
