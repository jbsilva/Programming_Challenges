// ============================================================================
//
//       Filename:  01182-coluna_na_matriz.cpp
//
//    Description:  URI 1182 - Coluna na Matriz
//
//        Version:  1.0
//        Created:  09/28/2012 02:19:47 PM
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
    int col;
    cin >> col;
    char op;
    cin >> op;
    double v;
    double soma = 0;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
        {
            cin >> v;
            if (j == col)
                soma += v;
        }
    if (op == 'M')
        soma /= 12;
    cout << fixed << setprecision(1) << soma << endl;
    return 0;
}
