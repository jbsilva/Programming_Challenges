// ============================================================================
//
//       Filename:  01421-tic_tac_toe.cpp
//
//    Description:  URI 1421 - Tic-Tac-Toe?
//
//        Version:  1.0 - Recebeu TLE
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
int cubo[41][41][41], n, x, y, z;


int verifica_ganhador()
{
    bool ganhou;
    for (z = 1; z <= n; z++)
    {
        // Eixo X
        for (y = 1; y <= n; y++)
        {
            ganhou = true;
            for (x = 1; x < n; x++)
                if (cubo[x][y][z] != cubo[x + 1][y][z])
                {
                    ganhou = false;
                    break;
                }
            if (ganhou && cubo[x][y][z] != -1)
                return cubo[x][y][z];
        }
        // Eixo Y
        for (x = 1; x <= n; x++)
        {
            ganhou = true;
            for (y = 1; y < n; y++)
                if (cubo[x][y][z] != cubo[x][y + 1][z])
                {
                    ganhou = false;
                    break;
                }
            if (ganhou && cubo[x][y][z] != -1)
                return cubo[x][y][z];
        }
    }
    // Eixo Z;
    ganhou = true;
    for (x = 1; x <= n; x++)
        for (y = 1; y <= n; y++)
        {
            bool ganhou = true;
            for (z = 1; z < n; z++)
                if (cubo[x][y][z] != cubo[x][y][z + 1])
                {
                    ganhou = false;
                    break;
                }
            if (ganhou && cubo[x][y][z] != -1)
                return cubo[x][y][z];
        }
    // Diagonais - Plano XY
    for (z = 1; z <= n; z++)
    {
        ganhou = true;
        for (x = 1, y = 1; x < n; x++, y++)
            if (cubo[x][y][z] != cubo[x + 1][y + 1][z])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
        ganhou = true;
        for (x = n, y = 1; y < n; x--, y++)
            if (cubo[x][y][z] != cubo[x - 1][y + 1][z])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
    }
    // Diagonais - Plano YZ
    for (x = 1; x <= n; x++)
    {
        ganhou = true;
        for (z = 1, y = 1; z < n; z++, y++)
            if (cubo[x][y][z] != cubo[x][y + 1][z + 1])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
        ganhou = true;
        for (z = n, y = 1; y < n; y++, z--)
            if (cubo[x][y][z] != cubo[x][y + 1][z - 1])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
    }
    // Diagonais - Plano XZ
    for (y = 1; y <= n; y++)
    {
        ganhou = true;
        for (x = 1, z = 1; x < n; x++, z++)
            if (cubo[x][y][z] != cubo[x + 1][y][z + 1])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
        ganhou = true;
        for (z = n, x = 1; x < n; z--, x++)
            if (cubo[x][y][z] != cubo[x + 1][y][z - 1])
            {
                ganhou = false;
                break;
            }
        if (ganhou && cubo[x][y][z] != -1)
            return cubo[x][y][z];
    }
    // Diagonais principais
    ganhou = true;
    for (x = 1, y = 1, z = 1; x < n ; x++, y++, z++)
        if (cubo[x][y][z] != cubo[x + 1][y + 1][z + 1])
        {
            ganhou = false;
            break;
        }
    if (ganhou && cubo[x][y][z] != -1)
        return cubo[x][y][z];
    ganhou = true;
    for (x = 1, y = 1, z = n; x < n ; x++, y++, z--)
        if (cubo[x][y][z] != cubo[x + 1][y + 1][z - 1])
        {
            ganhou = false;
            break;
        }
    if (ganhou && cubo[x][y][z] != -1)
        return cubo[x][y][z];
    ganhou = true;
    for (x = 1, y = n, z = n; x < n ; x++, y--, z--)
        if (cubo[x][y][z] != cubo[x + 1][y - 1][z - 1])
        {
            ganhou = false;
            break;
        }
    if (ganhou && cubo[x][y][z] != -1)
        return cubo[x][y][z];
    ganhou = true;
    for (x = 1, y = n, z = 1; x < n ; x++, y--, z++)
        if (cubo[x][y][z] != cubo[x + 1][y - 1][z + 1])
        {
            ganhou = false;
            break;
        }
    if (ganhou && cubo[x][y][z] != -1)
        return cubo[x][y][z];
    return -1;
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
                    ganhador = verifica_ganhador();
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

