// ============================================================================
//
//       Filename:  12290-counting_game.cpp (UVa)
//                  01400-counting_game.cpp (URI)
//
//    Description:  UVa 12290 - Counting Game
//                  URI 1400 - Counting Game
//
//        Version:  1.0
//        Created:  13/May/2013 13:38:09
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


#define max(a,b) ((a < b) ? (b) : (a))


inline bool tem7(int n)
{
    while (n)
    {
        if (n % 10 == 7)
            return true;
        n /= 10;
    }
    return false;
}


int main()
{
    int n, m, k; // n: número de pessoas; k: k-ésima palma da m-ésima pessoa
    while (scanf("%d %d %d", &n, &m, &k) && n)
    {
        int df = (n - m) * 2; // distância de ida e volta até o fim    ->
        int di = (m - 1) * 2; // distância de ida e volta até o início <-
        bool sentido = 0; // 1: direita, 0: esquerda

        // Trata pessoas que estão nas pontas
        if (!df || !di)
            df = di = max(df, di);

        int i = m, claps = 0;
        if (i % 7 == 0 || tem7(i)) claps++;
        while (claps < k)
        {
            if ((sentido = !sentido))
                i += df;
            else
                i += di;

            if (i % 7 == 0 || tem7(i))
                claps++;
        }
        printf("%d\n", i);
    }
    return 0;
}

