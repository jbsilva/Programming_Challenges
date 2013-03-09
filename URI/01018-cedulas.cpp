// ============================================================================
//
//       Filename:  01018-cedulas.cpp
//
//    Description:  URI 1018 - Cédulas
//
//        Version:  1.0
//        Created:  09/26/2012 11:16:06 PM
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
    int n, x;
    cin >> n;
    cout << n << endl;
    x = n / 100; n -= x * 100;
    cout << x << " nota(s) de R$ 100,00" << endl;
    x = n / 50; n -= x * 50;
    cout << x << " nota(s) de R$ 50,00" << endl;
    x = n / 20; n -= x * 20;
    cout << x << " nota(s) de R$ 20,00" << endl;
    x = n / 10; n -= x * 10;
    cout << x << " nota(s) de R$ 10,00" << endl;
    x = n / 5; n -= x * 5;
    cout << x << " nota(s) de R$ 5,00" << endl;
    x = n / 2; n -= x * 2;
    cout << x << " nota(s) de R$ 2,00" << endl;
    cout << n << " nota(s) de R$ 1,00" << endl;
    return 0;
}
