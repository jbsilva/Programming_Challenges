// ===================================================================
// 
//       Filename:  10071-back_to_high_school_physics.cpp
// 
//    Description:  10071 - Back to High School Physics
//                  
//                  a = vp/tp = d^2s/dt^2 => s = (vp*t^2)/(2*tp);
//                  t = 2*tp => s = 2*vp*tp
//
//        Version:  1.0
//        Created:  09/20/2012 12:54:48 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ===================================================================
#include <iostream>
using namespace std;

int main()
{
    int vp, tp;
    while (cin >> vp >> tp)
        cout << 2*vp*tp << endl;

    return 0;
}
