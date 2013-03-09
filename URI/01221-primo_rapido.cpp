// ============================================================================
//
//       Filename:  01221-primo_rapido.cpp
//
//    Description:  URI 1221 - Primo Rápido
//
//        Version:  1.0
//        Created:  10/06/2012 01:26:36 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>

inline int verifica_primo(int n)
{
    if (n == 2)
        return 1;
    if (n <= 1 || n % 2 == 0)
        return 0;
    int i, raiz;
    raiz = sqrt(n) + 1;
    for (i = 3; i <= raiz; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int cases, n;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &n);
        if (verifica_primo(n))
            puts("Prime");
        else
            puts("Not Prime");
    }
    return 0;
}
