// ============================================================================
//
//       Filename:  01421-tic_tac_toe.cpp
//
//    Description:  URI 1421 - Tic-Tac-Toe?
//
//        Version:  2.0 -- Verifica só onde precisa em vez do cubo inteiro
//        Created:  30/May/2013 13:56:13
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


// -1: Vazio, 0: Branco, 1: Azul
int cubo[40][40][40], n, x, y, z;


bool verifica_ganhador(int cor)
{
    int jx = x, jy = y, jz = z; // Coordenadas da jogada
    bool ganhou;
    // Eixo X
    ganhou = true;
    for (x = 1; x <= n; x++)
        if (cubo[x][jy][jz] != cor)
        {
            ganhou = false;
            break;
        }
    if (ganhou)
        return true;
    // Eixo Y
    ganhou = true;
    for (y = 1; y <= n; y++)
        if (cubo[jx][y][jz] != cor)
        {
            ganhou = false;
            break;
        }
    if (ganhou)
        return true;
    // Eixo Z
    ganhou = true;
    for (z = 1; z <= n; z++)
        if (cubo[jx][jy][z] != cor)
        {
            ganhou = false;
            break;
        }
    if (ganhou)
        return true;
    // Diagonais - Plano XY
    if (jx == jy) // se está numa diagonal
    {
        ganhou = true;
        for (x = 1, y = 1; x <= n; x++, y++)
            if (cubo[x][y][jz] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jx + jy == n + 1) // se está numa diagonal
    {
        ganhou = true;
        for (x = n, y = 1; y <= n; x--, y++)
            if (cubo[x][y][jz] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    // Diagonais - Plano YZ
    if (jy == jz) // se está numa diagonal
    {
        ganhou = true;
        for (y = 1, z = 1; y <= n; y++, z++)
            if (cubo[jx][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jy + jz == n + 1) // se está numa diagonal
    {
        ganhou = true;
        for (y = n, z = 1; z <= n; y--, z++)
            if (cubo[jx][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    // Diagonais - Plano XZ
    if (jx == jz) // se está numa diagonal
    {
        ganhou = true;
        for (x = 1, z = 1; x <= n; x++, z++)
            if (cubo[x][jy][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jx + jz == n + 1) // se está numa diagonal
    {
        ganhou = true;
        for (x = n, z = 1; z <= n; x--, z++)
            if (cubo[x][jy][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    // Diagonais principais
    if (jx == jy && jx == jz) // Se está na diagonal
    {
        ganhou = true;
        for (x = 1, y = 1, z = 1; x <= n ; x++, y++, z++)
            if (cubo[x][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jx == jy && jx + jz == n + 1) // Se está na diagonal
    {
        ganhou = true;
        for (x = 1, y = 1, z = n; x <= n ; x++, y++, z--)
            if (cubo[x][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jy == jz && jx + jy == n + 1) // Se está na diagonal
    {
        ganhou = true;
        for (x = 1, y = n, z = n; x <= n ; x++, y--, z--)
            if (cubo[x][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    if (jx == jz && jx + jy == n + 1) // Se está na diagonal
    {
        ganhou = true;
        for (x = 1, y = n, z = 1; x <= n ; x++, y--, z++)
            if (cubo[x][y][z] != cor)
            {
                ganhou = false;
                break;
            }
        if (ganhou)
            return true;
    }
    return false;
}


int main()
{
    int instancia = 1;
    while (scanf("%d", &n) && n)
    {
        memset(cubo, -1, sizeof(cubo));
        printf("Instancia %d\n", instancia++);
        int jogadas = n * n * n, cor = 0, ganhador = -1;
        for (int jogada = 1; jogada <= jogadas; jogada++)
        {
            scanf("%d %d", &x, &y);
            if (ganhador == -1)
            {
                z = 1;
                while (cubo[x][y][z] != -1)
                    z++;
                cubo[x][y][z] = cor;
                if (jogada >= n)
                    if (verifica_ganhador(cor))
                        ganhador = cor;
                cor = (cor + 1) % 2;
            }
        }
        if (ganhador == 0)
            puts("Branco ganhou\n");
        else if (ganhador == 1)
            puts("Azul ganhou\n");
        else
            puts("Empate\n");
    }
    return 0;
}

