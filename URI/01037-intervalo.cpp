// ============================================================================
//
//       Filename:  01037-intervalo.cpp
//
//    Description:  URI 1037 - Intervalo
//
//        Version:  1.0
//        Created:  09/27/2012 12:07:25 AM
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
    long double n;
    cin >> n;
    if (n < 0 || n > 100)
        cout << "Fora de intervalo" << endl;
    else if (n <= 25)
        cout << "Intervalo [0,25]" << endl;
    else if (n <= 50)
        cout << "Intervalo (25,50]" << endl;
    else if (n <= 75)
        cout << "Intervalo (50,75]" << endl;
    else
        cout << "Intervalo (75,100]" << endl;
    return 0;
}
