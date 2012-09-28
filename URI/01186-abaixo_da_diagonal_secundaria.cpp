// ============================================================================
// 
//       Filename:  01186-abaixo_da_diagonal_secundaria.cpp
// 
//    Description:  URI 1186 - Abaixo da Diagonal Secundária
// 
//        Version:  1.0
//        Created:  09/28/2012 01:30:43 PM
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
    char op;
    cin >> op;

    double soma = 0;
    double v;
    for (int i=0; i < 12; i++)
        for (int j=0; j < 12; j++)
        {
            cin >> v;
            if (i+j > 11)
                soma += v;
        }

    if (op == 'M')
        soma /= 66;

    cout << fixed << setprecision(1) << soma << endl;

    return 0;
}
