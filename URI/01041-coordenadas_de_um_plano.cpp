// ============================================================================
// 
//       Filename:  01041-coordenadas_de_um_plano.cpp
// 
//    Description:  URI 01041 - Coordenadas de um Ponto
// 
//        Version:  1.0
//        Created:  09/27/2012 08:15:00 AM
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
    double x, y;

    cin >> x >> y;

    if (x == 0 && y == 0)
        cout << "Origem" << endl;
    else if (x == 0)
        cout << "Eixo Y" << endl;
    else if (y == 0)
        cout << "Eixo X" << endl;
    if (x > 0 && y > 0)
        cout << "Q1" << endl;
    else if (x < 0 && y > 0)
        cout << "Q2" << endl;
    else if (x < 0 && y < 0)
        cout << "Q3" << endl;
    else if (x > 0 && y < 0)
        cout << "Q4" << endl;

    return 0;
}
