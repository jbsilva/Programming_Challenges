// ============================================================================
// 
//       Filename:  01030-a_lenda_de_flavious_josephus.cpp
// 
//    Description:  URI 1030 - A lenda de Flavious Josephus
// 
//        Version:  1.0
//        Created:  10/04/2012 01:49:21 AM
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
    int cases, qtd, skip;
    scanf("%d", &cases);

    for (int caso = 1; caso <= cases; caso++)
    {
        scanf("%d %d", &qtd, &skip);

        int anterior = 0;
        for (int n=2; n <= qtd; n++)
            anterior = (anterior + skip) % n;

        printf("Case %d: %d\n", caso, anterior+1);
    }

    return 0;
}
