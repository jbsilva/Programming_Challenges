// ============================================================================
// 
//       Filename:  01035-Teste_de_selecao_1.cpp
// 
//    Description:  URI 1035 - Teste de Seleção 1
// 
//        Version:  1.0
//        Created:  09/26/2012 11:45:41 PM
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b > c && d > a && c+d > a+b && c > 0 && d > 0 && a%2 == 0)
        cout << "Valores aceitos" << endl;
    else
        cout << "Valores nao aceitos" << endl;

    return 0;
}
