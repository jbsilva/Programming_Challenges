// ============================================================================
// 
//       Filename:  12531-hours_and_minutes.cpp
// 
//    Description:  UVa 12531 - Hours and Minutes
//
//                  Final Brasileira da Maratona de Programação 2012
//
//                  grau = abs(min/12-min%60)*6; if (grau>180) grau = 360-grau;
//                  Bastou verificar que para min em [0, 12*60],
//                  min/12 - min%60 cobria todos os inteiros de 0 até 60.
// 
//        Version:  1.0
//        Created:  11/Nov/2012 23:35:04
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>


int main()
{
    int n;

    while (scanf("%d", &n) != EOF)
        puts( (n%6 ? "N" : "Y") );

    return 0;
}
