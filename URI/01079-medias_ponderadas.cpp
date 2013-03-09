// ============================================================================
//
//       Filename:  01079-medias_ponderadas.cpp
//
//    Description:  URI 1079 - Médias Ponderadas
//
//        Version:  1.0
//        Created:  09/29/2012 09:03:32 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int cases;
    scanf("%d", &cases);
    double a, b, c;
    while (cases--)
    {
        scanf("%lf %lf %lf", &a, &b, &c);
        printf("%.1lf\n", (a * 2 + b * 3 + c * 5) / 10);
    }
    return 0;
}
