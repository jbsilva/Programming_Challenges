// ============================================================================
// 
//       Filename:  01002-area_of_a_circle.cpp
// 
//    Description:  URI 1002 - Area of a Circle
// 
//        Version:  1.0
//        Created:  09/26/2012 09:41:28 PM
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
    double r;
    cin >> r;
    cout << fixed << setprecision(4) << "A=" << pi*r*r << endl;

    return 0;
}
