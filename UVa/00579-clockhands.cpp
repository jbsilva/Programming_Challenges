// ============================================================================
//
//       Filename:  00579-clockhands.cpp
//
//    Description:  UVa 579 - ClockHands
//
//        Version:  1.0
//        Created:  15/Jul/2013 16:52:35
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


int main()
{
    int h, m;
    while (scanf("%d:%d", &h, &m) && (h || m))
    {
        double ah = 30.0 * h + 0.5 * m; // (360/12) = 30.0, (360/(12*60)) = 0.5
        double am = 6.0 * m;            // (360/60) = 6.0
        double ad = (ah - am);

        if (ad < 0.0)
            ad = -ad;
        if (ad > 180.0)
            ad = 360.0 - ad;

        printf("%.3f\n", ad);
    }
    return 0;
}

