// ============================================================================
//
//       Filename:  01155-sequencia_s.cpp
//
//    Description:  URI 1155 - Sequência S
//                  Série Harmônica
//
//        Version:  1.0
//        Created:  09/30/2012 08:42:50 PM
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
    double sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += 1.0 / i;
    printf("%.2lf\n", sum);
    return 0;
}
