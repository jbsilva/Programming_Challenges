// ============================================================================
// 
//       Filename:  01006-average_2.cpp
// 
//    Description:  URI 1006 - Average 2
// 
//        Version:  1.0
//        Created:  09/26/2012 10:02:27 PM
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
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(1) << "MEDIA = " << (a*2 + b*3 + c*5)/10 << endl;

    return 0;
}
