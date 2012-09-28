// ============================================================================
// 
//       Filename:  01038-lanche.cpp
//
//    Description:  URI 1038 - Lanche
// 
//        Version:  1.0
//        Created:  09/26/2012 08:07:28 AM
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
    double preco[] = {0, 4.00, 4.50, 5.00, 2.00, 1.50};
    int codigo, qtd;
    cin >> codigo >> qtd;

    cout << fixed << setprecision(2) << "Total: R$ " << qtd*preco[codigo] << endl;
    return 0;
}
