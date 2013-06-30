// ============================================================================
//
//       Filename:  11152-colourful_flowers.cpp (UVa)
//                  01219-colourful_flowers.cpp (URI)
//
//    Description:  UVa 11152 - Colourful Flowers
//                  URI 1219 - Colourful Flowers
//
//        Version:  1.0
//        Created:  30/Jun/2013 16:36:47
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
    const double pi = 3.1415926535897;
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        int p = (a + b + c);                              // Perímetro
        double s =  p / 2.0;                              // Semiperímetro
        double A = sqrt(s * (s - a) * (s - b) * (s - c)); // Área do triângulo
        double r = 2.0 * A / p;                           // Raio circ inscrito
        double R = (a * b * c) / (4 * A);                 // Raio circ escrito
        double C = pi * R * R;                            // Área circ escrito
        double ros = pi * r * r;                          // Área circ inscrito
        double vio = A - ros;                             // Violets
        double sun = C - A;                               // Sunflowers
        printf("%.4f %.4f %.4f\n", sun, vio, ros);
    }
    return 0;
}

