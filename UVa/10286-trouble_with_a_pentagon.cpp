// ============================================================================
// 
//       Filename:  10286-trouble_with_a_pentagon.cpp (UVa)
//                  01292-trouble_with_a_pentagon.cpp (URI)
//
//    Description:  UVa 10286 - Trouble With a Pentagon
//                  URI 1292 - Trouble With a Pentagon
//
//                  Na minha 1a tentativa (WA), defini a constante k como:
//                  const long double k = 1.067395681711181869259263762671132L;
//                  Cheguei no número 1.06739 usando a lei dos senos:
//                      p/sin(63) = q/sin(108)
//                      q = sin(108)/sin(63) * p
//                      q = 1.06739*p
//                  Não sei porque assim recebeu WA, mas usando a <cmath> não.
//
//        Version:  1.0
//        Created:  12/Mar/2013 17:01:31
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
    const double pi = 3.1415926535897932384626433832795028841972;
    double p, k = sin(108*pi/180)/sin(63*pi/180);
    while (scanf("%lf", &p) != EOF)
        printf("%.10f\n", k*p);

    return 0;
}

