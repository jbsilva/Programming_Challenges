// ============================================================================
//
//       Filename:  01067-numeros_impares.cpp
//
//    Description:  URI 1067 - Números Ímpares
//
//        Version:  1.0
//        Created:  09/29/2012 04:35:52 PM
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
    for (int i = 1; i <= x; i += 2)
        cout << i << endl;
    return 0;
}
