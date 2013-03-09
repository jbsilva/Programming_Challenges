// ============================================================================
//
//       Filename:  8308-robo_colecionador.cpp  (SPOJ BR)
//                  01121-robo_colecionador.cpp (URI)
//
//    Description:  SPOJ BR 8308 - Robô Colecionador
//                  URI 1121 - Robô Colecionador
//
//                  Primeira Fase da Maratona de Programação 2010
//                  br.spoj.pl/problems/ROBOCOL
//
//        Version:  1.0
//        Created:  08/12/2012 03:32:29 PM
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
    int n; // linhas
    int m; // colunas
    int s; // qtd de instrucoes
    char arena[101][101];
    char inst;
    int orientacao = 0; // 0-N, 1-L, 2-S, 3-O
    int x = 0, y = 0; // posicao atual do robo
    int i, j;
    while (scanf("%d %d %d ", &n, &m, &s) && (n || m || s))
    {
        // le a matriz da arena
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                scanf("%c ", &arena[i][j]);
                if (arena[i][j] == 'N')
                {
                    orientacao = 0;
                    x = i; y = j;
                    arena[i][j] = '.';
                }
                else if (arena[i][j] == 'L')
                {
                    orientacao = 1;
                    x = i; y = j;
                    arena[i][j] = '.';
                }
                else if (arena[i][j] == 'S')
                {
                    orientacao = 2;
                    x = i; y = j;
                    arena[i][j] = '.';
                }
                else if (arena[i][j] == 'O')
                {
                    orientacao = 3;
                    x = i; y = j;
                    arena[i][j] = '.';
                }
            }
        // le a sequencia de instrucoes
        int figurinhas_coletadas = 0;
        for (i = 0; i < s; i++)
        {
            scanf("%c ", &inst);
            int x_anterior = x;
            int y_anterior = y;
            switch (inst)
            {
                case 'D':
                    orientacao = (orientacao + 1) % 4;
                    break;
                case 'E':
                    if (orientacao == 0)
                        orientacao = 3;
                    else
                        orientacao -= 1;
                    break;
                case 'F':
                    if (orientacao == 0 && x != 0)
                        x--;
                    else if (orientacao == 1 && y != m - 1)
                        y++;
                    else if (orientacao == 2 && x != n - 1)
                        x++;
                    else if (orientacao == 3 && y != 0)
                        y--;
                    if (arena[x][y] == '*')
                    {
                        figurinhas_coletadas++;
                        arena[x][y] = '.';
                    }
                    else if (arena[x][y] == '#')
                    {
                        x = x_anterior;
                        y = y_anterior;
                    }
                    break;
            }
        }
        printf("%d\n", figurinhas_coletadas);
    }
    return 0;
}
