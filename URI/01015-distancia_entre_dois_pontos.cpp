// ============================================================================
//
//       Filename:  01015-distancia_entre_dois_pontos.cpp
//
//    Description:  URI 1015 - Distância entre dois pontos
//
//        Version:  1.0
//        Created:  09/26/2012 11:00:49 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << fixed << setprecision(4) << hypot(x2 - x1, y2 - y1) << endl;
    return 0;
}
