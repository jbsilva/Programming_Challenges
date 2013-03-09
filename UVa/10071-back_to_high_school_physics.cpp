// ===================================================================
//
//       Filename:  10071-back_to_high_school_physics.cpp (UVa)
//                  01197-back_to_high_school_physics.cpp (URI)
//
//    Description:  UVa 10071 - Back to High School Physics
//                  URI 1197 - Back to High School Physics
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
#include <cstdio>

int main()
{
    int vp, tp;
    while (scanf("%d %d", &vp, &tp) != EOF)
        printf("%d\n", 2 * vp * tp);
    return 0;
}
