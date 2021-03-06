// ============================================================================
//
//       Filename:  01187-area_superior.cpp
//
//    Description:  URI 1187 - Área Superior
//
//        Version:  1.0
//        Created:  09/28/2012 01:29:07 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    char op;
    cin >> op;
    double soma = 0;
    double v;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            cin >> v;
            if (i < j && i + j < 11)
                soma += v;
        }
    if (op == 'M')
        soma /= 30;
    cout << fixed << setprecision(1) << soma << endl;
    return 0;
}
