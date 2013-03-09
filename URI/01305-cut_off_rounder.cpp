// ============================================================================
//
//       Filename:  01305-cut_off_rounder.cpp
//
//    Description:  URI 1305 - Cut Off Rounder
//
//        Version:  1.0
//        Created:  06/Mar/2013 21:03:27
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
    double num, cutoff;
    while (scanf("%lf", &num) != EOF)
    {
        scanf("%lf", &cutoff);
        printf("%d\n", (num - int(num) >= cutoff ? (int)(num + 1) : (int)num));
    }
    return 0;
}

