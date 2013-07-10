// ============================================================================
//
//       Filename:  00591-box_of_bricks.cpp
//
//    Description:  UVa 591 - Box of Bricks
//
//        Version:  1.0
//        Created:  10/Jul/2013 18:56:38
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


int main()
{
    int n, set = 0, h[50];
    while (scanf("%d", &n) && n)
    {
        int soma = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &h[i]);
            soma += h[i];
        }

        int media = soma / n;
        int moves = 0;
        for (int i = 0; i < n; i++)
            if (h[i] > media)
                moves += h[i] - media;

        printf("Set #%d\n", ++set);
        printf("The minimum number of moves is %d.\n\n", moves);
    }
    return 0;
}

