// ============================================================================
//
//       Filename:  01052-mes.cpp
//
//    Description:  URI 1052 - Mês
//
//        Version:  1.0
//        Created:  09/28/2012 05:09:51 PM
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
    string mes[] = {"", "January", "Febuary", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"
                   };
    int n;
    cin >> n;
    cout << mes[n] << endl;
    return 0;
}
