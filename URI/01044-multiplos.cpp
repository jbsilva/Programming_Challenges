// ============================================================================
//
//       Filename:  01044-multiplos.cpp
//
//    Description:  URI 1042 - Multiplos
//
//        Version:  1.0
//        Created:  09/27/2012 08:30:00 AM
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
    int a, b;
    cin >> a >> b;
    if (a % b == 0 || b % a == 0)
        cout << "Sao Multiplos" << endl;
    else
        cout << "Nao sao Multiplos" << endl;
    return 0;
}
