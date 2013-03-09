// ============================================================================
//
//       Filename:  01099-soma_de_impares_consecutivos_ii.cpp
//
//    Description:  URI 1099 - Soma de Ímpares Consecutivos II
//
//        Version:  1.0
//        Created:  09/30/2012 02:02:11 AM
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
    int x, y, max, min, cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d %d", &x, &y);
        if (x > y)
        {
            max = x;
            min = y;
        }
        else
        {
            max = y;
            min = x;
        }
        if (min % 2 == 0) min--;
        int soma = 0;
        for (int i = min + 2; i < max; i += 2)
            soma += i;
        printf("%d\n", soma);
    }
    return 0;
}
