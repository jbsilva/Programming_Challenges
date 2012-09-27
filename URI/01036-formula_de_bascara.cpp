// ============================================================================
// 
//       Filename:  01036-formula_de_bascara.cpp
// 
//    Description:  URI 1036 - Fórmula de Báscara
// 
//        Version:  1.0
//        Created:  09/26/2012 11:51:34 PM
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
    int a, b, c;
    cin >> a >> b >> c;

    int delta = b*b - 4*a*c;
    // a=0 torna a eq. linear, não calculável por báscara
    if (a == 0 || delta < 0)
        cout << "Impossivel calcular" << endl;
    else
    {
        cout << fixed << setprecision(5)
             << "R1 = " << (-b + sqrt(delta))/(2*a) << endl
             << "R2 = " << (-b - sqrt(delta))/(2*a) << endl;
    }

    return 0;
}
