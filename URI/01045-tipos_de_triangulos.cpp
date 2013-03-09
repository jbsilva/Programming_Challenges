// ============================================================================
//
//       Filename:  01045-tipos_de_triangulos.cpp
//
//    Description:  URI 1040 - Tipos de Triangulos
//
//        Version:  1.0
//        Created:  09/27/2012 08:35:00 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <algorithm>
using namespace std;

bool inverso(double a, double b)
{
    return a > b;
}

int main()
{
    double l[3];
    for (int i = 0; i < 3; i++)
        cin >> l[i];
    sort(l, &l[4], inverso);
    if (l[0] > l[1] + l[2])
        cout << "NAO FORMA TRIANGULO" << endl;
    else if (l[0]*l[0] == l[1]*l[1] + l[2]*l[2])
        cout << "TRIANGULO RETANGULO" << endl;
    else if (l[0]*l[0] > l[1]*l[1] + l[2]*l[2])
        cout << "TRIANGULO OBTUSANGULO" << endl;
    else if (l[0]*l[0] < l[1]*l[1] + l[2]*l[2])
        cout << "TRIANGULO ACUTANGULO" << endl;
    if (l[0] == l[1] && l[0] == l[2])
        cout << "TRIANGULO EQUILATERO" << endl;
    else if (l[0] == l[1] || l[0] == l[2] || l[1] == l[2])
        cout << "TRIANGULO ISOSCELES" << endl;
    return 0;
}
