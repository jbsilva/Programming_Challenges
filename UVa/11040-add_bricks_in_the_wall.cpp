// ============================================================================
//
//       Filename:  11040-add_bricks_in_the_wall.cpp (UVa)
//                  01426-add_bricks_in_the_wall.cpp (URI)
//
//    Description:  UVa 11040 - Add Bricks in The Wall
//                  URI 1426 - Add Bricks in The Wall
//
//        Version:  1.0
//        Created:  24/Jun/2013 18:37:50
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
    int N, w[10][10];
    scanf("%d", &N);
    while (N--)
    {
        for (int i = 0; i < 9; i += 2)
            for (int j = 0; j <= i; j += 2)
                scanf("%d", &w[i][j]);

        // Preenche a última linha
        for (int j = 1; j < 9; j += 2)
            w[8][j] = (w[6][j - 1] - w[8][j - 1] - w[8][j + 1]) / 2;

        // Com a última linha dá para construir todo o triângulo
        for (int i = 7; i > 0; i--)
            for (int j = 0; j <= i; j++)
                w[i][j] = w[i + 1][j] + w[i + 1][j + 1];

        // Imprime resposta
        for (int i = 0; i < 9; i++)
        {
            printf("%d", w[i][0]);
            for (int j = 1; j <= i; j++)
                printf(" %d", w[i][j]);
            putchar('\n');
        }
    }
    return 0;
}

