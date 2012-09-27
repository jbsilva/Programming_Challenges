// ============================================================================
// 
//       Filename:  01011-sphere.cpp
// 
//    Description:  URI 1011 - Sphere
// 
//        Version:  1.0
//        Created:  09/26/2012 10:34:17 PM
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

const double pi = 3.14159;

int main()
{
    int r;
    cin >> r;

    cout << fixed << setprecision(3)
         << "VOLUME = " << 4.0/3 * pi * r * r * r << endl;

    return 0;
}
