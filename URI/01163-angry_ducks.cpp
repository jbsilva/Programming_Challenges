// ============================================================================
//
//       Filename:  01163-angry_ducks.cpp
//
//    Description:  URI 1163 - Angry Ducks
//
//        Version:  1.0
//        Created:  26/Feb/2013 05:07:16
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>


int main()
{
    long double h, a, v, dx; // altura, ângulo, velocidade, deslocamento em x
    int p1, p2, trys; // limites da cidade Nlogônia
    const long double k = 3.14159 / 180.0;
    const long double g = 9.80665;
    const long double EPS = 10E-6;
    while (scanf("%Lf %d %d %d", &h, &p1, &p2, &trys) != EOF)
    {
        while (trys--)
        {
            scanf("%Lf %Lf", &a, &v);
            a *= k;
            dx = v * cos(a) * (v * sin(a) + sqrt(v * v * sin(a) * sin(a) + 2 * g * h)) / g;
            if (dx + EPS >= p1 && dx <= p2 + EPS)
                printf("%.5Lf -> DUCK\n", dx);
            else
                printf("%.5Lf -> NUCK\n", dx);
        }
    }
    return 0;
}

