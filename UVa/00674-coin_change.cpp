// ============================================================================
//
//       Filename:  00674-coin_change.cpp
//
//    Description:  UVa 674 - Coin Change
//
//                  Memoization usando a explicação encontrada no livro
//                  Competitive Programming 3ed.
//
//        Version:  1.0
//        Created:  19/Jul/2013 16:24:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int coinValue[5] = {1, 5, 10, 25, 50}, memo[5][7490];


int ways(int type, int value)
{
    // 1 jeito: Não usa nenhuma moeda
    if (value == 0)
        return 1;

    // Não existem moedas negativas
    if (value < 0)
        return 0;

    // Só existe 5 moedas
    if (type >= 5)
        return 0;

    // Já estava pré-calculado
    if (memo[type][value] != -1)
        return memo[type][value];

    memo[type][value] = ways(type + 1, value) + ways(type, value - coinValue[type]);

    return memo[type][value];
}


int main()
{
    memset(memo, -1, sizeof(memo));

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", ways(0, n));

    return 0;
}

