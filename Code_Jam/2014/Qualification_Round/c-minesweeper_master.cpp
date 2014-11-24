// ============================================================================
//  
//       Filename:  c-minesweeper_master.cpp
//
//    Description:  Problem C - Minesweeper Master
//                  Qualification Round 2014
//
//                  Resolvo um problema equivalente: O campo inicia todo cheio
//                  de bombas e é necessário removê-las até sobrar apenas M
//                  bombas.
//
//        Version:  1.0
//        Created:  12/Apr/2014 03:19:38
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


char f[55][55];
bool visitado[55][55];
int T, R, C, M;
int to_remove;


void imprime()
{
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
            putchar(f[i][j]);
        putchar('\n');
    }
}

// Quantidade de bombas ao redor do ponto (r,c)
int bombs_around(int r, int c)
{
    int pontos = 0;
    for (int i = r-1; i <= r+1; i++)
        for (int j = c-1; j <= c+1; j++)
            if (f[i][j] == '*')
                pontos++;

    return pontos;
}


bool remove_around(int r, int c)
{
    if (visitado[r][c])
        return false;
    visitado[r][c] = true;

    if (to_remove == 0)
        return true;

    if (to_remove < bombs_around(r,c))
        return false;
    else
    {
        // Remove bombas ao redor de (r,c)
        for (int i = r-1; i <= r+1; i++)
            for (int j = c-1; j <= c+1; j++)
                if (f[i][j] == '*')
                {
                    f[i][j] = '.';
                    to_remove--;
                }

        if (to_remove == 0)
            return true;
        else
        {
            for (int i = r-1; i <= r+1; i++)
                for (int j = c-1; j <= c+1; j++)
                    if (f[i][j] == '.')
                        remove_around(i,j);
        }
    }

    if (to_remove == 0)
        return true;
    else
        return false;
}


int main()
{
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        memset(visitado, 0, sizeof(visitado));

        printf("Case #%d:\n", caso);
        scanf("%d %d %d", &R, &C, &M);

        // Cria uma borda
        for (int i = 0; i <= R+1; i++)
            f[i][0] = '?';
        for (int i = 0; i <= R+1; i++)
            f[i][C+1] = '?';
        for (int j = 0; j <= C+1; j++)
            f[0][j] = '?';
        for (int j = 0; j <= C+1; j++)
            f[R+1][j] = '?';

        // Inicia cheio de bombas
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                f[i][j] = '*';

        // Clique vai no último quadrado
        f[R][C] = 'c';

        // Quantidade de bombas que ainda devem ser removidas
        to_remove = R * C - M - 1;

        // Remove bombas
        if (remove_around(R, C))
            imprime();
        else
            puts("Impossible");
    }
    return 0;
}

