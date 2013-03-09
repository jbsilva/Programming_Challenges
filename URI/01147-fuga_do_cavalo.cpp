// ============================================================================
//
//       Filename:  01147-fuga_do_cavalo.cpp
//
//    Description:  URI 1147 - Fuga do Cavalo
//
//        Version:  1.0
//        Created:  04/Feb/2013 00:22:48
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
    // Margem de 2 casas em cada lado. 0 -> casa segura; 1 -> casa sob ataque
    bool tab[12][12];
    int caso = 0, l, lin, atk;
    char c, col;
    // Preenche bordas
    for (int j = 0; j < 12; j++)
        tab[0][j] = tab[1][j] = tab[10][j] = tab[11][j] = 1;
    for (int i = 2; i < 10; i++)
        tab[i][0] = tab[i][1] = tab[i][10] = tab[i][11] = 1;
    while (scanf("%d%c", &l, &c) && l)
    {
        // Limpa tabuleiro => Marca todas as casas do centro como seguras.
        for (int i = 2; i < 10; i++)
            for (int j = 2; j < 10; j++)
                tab[i][j] = 0;
        // Posição do cavalo. a -> tab[][2]; h -> tab[][9]
        l++; c -= ('a' - 2);
        for (int i = 0; i < 8; i++)
        {
            scanf("%d%c", &lin, &col);
            lin++; col -= ('a' - 2);
            // Marca casas sob ataque do peão
            tab[lin - 1][(int)col - 1] = tab[lin - 1][(int)col + 1] = 1;
        }
        atk = tab[l + 2][c - 1] + tab[l + 2][c + 1] + tab[l + 1][c - 2] + tab[l + 1][c + 2] +
              tab[l - 2][c - 1] + tab[l - 2][c + 1] + tab[l - 1][c - 2] + tab[l - 1][c + 2];
        printf("Caso de Teste #%d: %d movimento(s).\n", ++caso, 8 - atk);
    }
    return 0;
}

