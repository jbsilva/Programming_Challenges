// ============================================================================
//
//       Filename:  01165-numero_primo.cpp
//
//    Description:  URI 1165 - Número Primo
//                  Uso um crivo de Eratóstenes
//
//        Version:  1.0
//        Created:  09/29/2012 07:44:14 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>
#include <cstring>

typedef unsigned int UI;
const UI MAX = 10000002;
const UI TAM = (MAX - 1) / 2;

int main()
{
    bool eh_composto[TAM];
    memset(eh_composto, 0, sizeof(eh_composto));
    eh_composto[0] = 1; // 1 é composto
    const UI LIM = sqrt(MAX) / 2;
    for (UI i = 1; i <= LIM; i++)
        if (!eh_composto[i])
            for (UI j = 2 * i * (i + 1); j < TAM; j += 2 * i + 1)
                eh_composto[j] = 1;
    int cases, x;
    scanf("%u", &cases);
    while (cases--)
    {
        scanf("%u", &x);
        if (x != 2 && (x % 2 == 0 || eh_composto[(x - 1) / 2]))
            printf("%u nao eh primo\n", x);
        else
            printf("%u eh primo\n", x);
    }
    return 0;
}
