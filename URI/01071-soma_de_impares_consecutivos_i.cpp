// ============================================================================
//
//       Filename:  01071-soma_de_impares_consecutivos_i.cpp
//
//    Description:  URI 1071 - Soma de Ímpares Consecutivos I
//
//        Version:  1.0
//        Created:  09/29/2012 06:54:00 PM
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
    int x, y, low, high, sum;
    cin >> x >> y;
    if (x < y)
    {
        low = x;
        high = y;
    }
    else
    {
        low = y;
        high = x;
    }
    sum = 0;
    for (int i = low + 1; i < high; i++)
        if (i % 2)
            sum += i;
    cout << sum << endl;
    return 0;
}
