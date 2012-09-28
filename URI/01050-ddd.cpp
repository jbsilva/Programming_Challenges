// ============================================================================
// 
//       Filename:  01050-ddd.cpp
// 
//    Description:  URI 1050 - DDD
// 
//        Version:  1.0
//        Created:  09/28/2012 10:29:49 AM
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
    int ddd;
    cin >> ddd;

    switch (ddd)
    {
        case 61:
            cout << "Brasilia" << endl; break;
        case 71:
            cout << "Salvador" << endl; break;
        case 11:
            cout << "Sao Paulo" << endl; break;
        case 21:
            cout << "Rio de Janeiro" << endl; break;
        case 32:
            cout << "Juiz de Fora" << endl; break;
        case 19:
            cout << "Campinas" << endl; break;
        case 27:
            cout << "Vitoria" << endl; break;
        case 31:
            cout << "Belo Horizonte" << endl; break;
        default:
            cout << "DDD nao cadastrado" << endl; break;
    }

    return 0;
}
