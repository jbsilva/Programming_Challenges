// ============================================================================
// 
//       Filename:  01164-numero_perfeito.cpp
// 
//    Description:  URI 1164 - Número Perfeito
// 
//        Version:  1.0
//        Created:  09/29/2012 11:40:42 PM
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
    int cases;
    scanf("%d", &cases);

    int n;
    while (cases--)
    {
        scanf("%d", &n);
        switch(n)
        {
            case 6:
            case 28:
            case 496:
            case 8128:
            case 33550336: printf("%d eh perfeito\n", n); break;
            default: printf("%d nao eh perfeito\n", n);
        }
    }

    return 0;
}
