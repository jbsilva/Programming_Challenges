// ============================================================================
// 
//       Filename:  01178-Preenchimento_de_vetor_iii.cpp
// 
//    Description:  URI 1178 - Preenchimento de Vetor III
// 
//        Version:  1.0
//        Created:  09/28/2012 03:32:01 PM
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
    double x;
    cin >> x;

    cout << fixed << setprecision(4);
    for (int i=0; i < 100; i++)
    {
        cout << "N[" << i << "] = " << x << endl;
        x /= 2;
    }

    return 0;
}
