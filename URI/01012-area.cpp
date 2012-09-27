// ============================================================================
// 
//       Filename:  01012-area.cpp
// 
//    Description:  URI 1012 - Area
// 
//        Version:  1.0
//        Created:  09/26/2012 10:37:26 PM
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

const double pi = 3.14159;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(3)
         << "TRIANGULO: " << a*c/2<< endl
         << "CIRCULO: " << pi * c * c << endl
         << "TRAPEZIO: " << (b+a)*c/2 << endl
         << "QUADRADO: " << b*b << endl
         << "RETANGULO: " << a*b << endl;

    return 0;
}
