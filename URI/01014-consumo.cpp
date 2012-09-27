// ============================================================================
// 
//       Filename:  01014-consumo.cpp
// 
//    Description:  URI 1014 - Consumo
// 
//        Version:  1.0
//        Created:  09/26/2012 10:57:13 PM
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
    int dist;
    double combustivel;

    cin >> dist >> combustivel;

    cout << fixed << setprecision(3) 
         << dist/combustivel << " km/l" << endl;

    return 0;
}
