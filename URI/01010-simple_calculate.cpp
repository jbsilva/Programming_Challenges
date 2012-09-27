// ============================================================================
// 
//       Filename:  01010-simple_calculate.cpp
// 
//    Description:  URI 1010 - Simple Calculate
// 
//        Version:  1.0
//        Created:  09/26/2012 10:28:37 PM
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
    int code[2], units[2];
    double price[2]; 

    cin >> code[0] >> units[0] >> price[0]
        >> code[1] >> units[1] >> price[1];

    cout << fixed << setprecision(2) << "VALOR A PAGAR: R$ "
         << units[0]*price[0] + units[1]*price[1] << endl;

    return 0;
}
