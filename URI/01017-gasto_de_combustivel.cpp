// ============================================================================
//
//       Filename:  01017-gasto_de_combustivel.cpp
//
//    Description:  URI 1017 - Gasto de Combustível
//
//        Version:  1.0
//        Created:  09/26/2012 11:09:59 PM
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
    int tempo, vel;
    cin >> tempo >> vel;
    cout << fixed << setprecision(3) << (tempo * vel) / 12.0 << endl;
    return 0;
}
