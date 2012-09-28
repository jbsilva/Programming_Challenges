// ============================================================================
// 
//       Filename:  01183-acima_da_diagonal_principal.cpp
// 
//    Description:  URI 1183 - Acima da Diagonal Principal
// 
//        Version:  1.0
//        Created:  09/28/2012 01:36:00 PM
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
            if (i < j)
                soma += v;
        }

    if (op == 'M')
        soma /= 66;

    cout << fixed << setprecision(1) << soma << endl;

    return 0;
}
