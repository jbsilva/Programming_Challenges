// ============================================================================
// 
//       Filename:  01051-imposto_de_renda.cpp
// 
//    Description:  URI 1051 - Imposto de Renda
// 
//        Version:  1.0
//        Created:  09/28/2012 10:49:37 AM
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
    cout << fixed << setprecision(2);

    double salario;
    cin >> salario;

    if (salario <= 2000)
        cout << "Isento" << endl;
    else
    {
        salario -= 2000;
        if (salario <= 1000)
            cout << "R$ " << 0.08*salario << endl;
        else
        {
            salario -= 1000;
            if (salario <= 1500)
                cout << "R$ " << 0.08*1000 + 0.18*salario << endl;
            else
            {
                salario -= 1500;
                cout << "R$ " << 0.08*1000 + 0.18*1500 + salario*0.28 << endl;
            }
        }
    }
    
    return 0;
}
