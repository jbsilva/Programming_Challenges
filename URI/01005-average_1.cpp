// ============================================================================
//
//       Filename:  01005-average_1.cpp
//
//    Description:  URI 1005 - Average 1
//
//        Version:  1.0
//        Created:  09/26/2012 09:54:00 PM
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
    double a, b;
    cin >> a >> b;
    cout << fixed << setprecision(5)
         << "MEDIA = " << (3.5 * a + 7.5 * b) / 11 << endl;
    return 0;
}
