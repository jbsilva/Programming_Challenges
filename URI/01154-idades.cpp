// ============================================================================
//
//       Filename:  01154-idades.cpp
//
//    Description:  URI 1154 - Idades
//
//        Version:  1.0
//        Created:  09/30/2012 08:38:27 PM
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
    int i, sum = 0, qtd = 0;
    while (scanf("%d", &i) && i >= 0)
    {
        sum += i;
        qtd++;
    }
    printf("%.2lf\n", (double)sum / qtd);
    return 0;
}
