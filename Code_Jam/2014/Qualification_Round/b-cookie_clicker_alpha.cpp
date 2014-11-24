// ============================================================================
//
//       Filename:  b-cookie_clicker_alpha.cpp
//
//    Description:  Problem B - Cookie Clicker Alpha
//                  Qualification Round 2014
//
//                  You start producing 2 cookies per second
//
//        Version:  1.0
//        Created:  12/Apr/2014 01:34:37
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
    int T;
    double C; // C: cost of cookie farm
    double F; // F: extra cookies per second from each farm
    double X; // X: cookies to win

    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%lf %lf %lf", &C, &F, &X);

        double total = 0.0; // Total time
        double prod = 2.0;  // Production rate

        // Buy farms while worth it
        do
        {
            double sem_farm = X / prod;
            double wait = C / prod;
            double com_farm = wait + X / (prod + F);

            if (com_farm < sem_farm)
            {
                total += wait;
                prod += F;
            }
            else
            {
                total += sem_farm;
                break;
            }
        } while (42);

        printf("Case #%d: %.7f\n", caso, total);
    }
    return 0;
}

