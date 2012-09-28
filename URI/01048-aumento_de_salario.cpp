// ============================================================================
// 
//       Filename:  01048-aumento_de_salario.cpp
// 
//    Description:  URI 1048 - Aumento de Salário
// 
//        Version:  1.0
//        Created:  09/28/2012 09:13:46 AM
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
    double salario;
    int percentual = 0.0;

    cin >> salario;

    if (salario <= 400)
        percentual = 15;
    else if (salario <= 800)
        percentual = 12;
    else if (salario <= 1200)
        percentual = 10;
    else if (salario <= 2000)
        percentual = 7;
    else if (salario > 2000)
        percentual = 4;

    double reajuste = salario*percentual/100;
    double novo = salario + reajuste;

    cout << fixed << setprecision(2);
    cout << "Novo salario: " << novo << endl;
    cout << "Reajuste ganho: " << reajuste << endl;
    cout << "Em percentual: " << percentual << " %" << endl;

    return 0;
}
