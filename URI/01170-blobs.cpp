// ============================================================================
//
//       Filename:  01170-blobs.cpp
//
//    Description:  URI 1170 - Blobs
//
//        Version:  1.0
//        Created:  11/Oct/2012 09:05:53
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
    int cases;
    double comida;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%lf", &comida);
        int dias = 0;
        while (comida > 1)
        {
            comida /= 2;
            dias++;
        }
        printf("%d dias\n", dias);
    }
    return 0;
}
