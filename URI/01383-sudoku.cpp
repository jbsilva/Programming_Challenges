// ============================================================================
//
//       Filename:  01383-sudoku.cpp
//
//    Description:  URI 1354 - Sudoku
//
//        Version:  1.0
//        Created:  01/May/2013 15:36:15
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


int t[10][10];


bool verifica()
{
    int sum;
    // Linhas
    for (int i = 0; i < 9; i++)
    {
        sum = 0;
        for (int j = 0; j < 9; j++)
            sum += t[i][j];
        if (sum != 45)
            return false;
    }
    // Colunas
    for (int j = 0; j < 9; j++)
    {
        sum = 0;
        for (int i = 0; i < 9; i++)
            sum += t[i][j];
        if (sum != 45)
            return false;
    }
    // sub-matrizes
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
        {
            sum = 0;
            for (int k = 0; k < 3; k++)
                for (int l = 0; l < 3; l++)
                    sum += t[i + k][j + l];
            if (sum != 45)
                return false;
        }
    return true;
}


int main()
{
    int n;
    scanf("%d", &n);
    for (int instancia = 1; instancia <= n; instancia++)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                scanf("%d", &t[i][j]);
        printf("Instancia %d\n%s\n\n", instancia,
                                       (verifica() ? "SIM" : "NAO"));
    }
    return 0;
}

