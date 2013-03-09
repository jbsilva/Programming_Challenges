// ============================================================================
//
//       Filename:  01206-desafio_de_sao_petersburgo.cpp
//
//    Description:  URI 1206 - Desafio de São Petersburgo
//                  Seletiva IME 2012. Problema E: Desafio de São Petersburgo
//
//        Version:  1.0
//        Created:  10/06/2012 02:03:20 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

char tab[10][10];  // casa diferente de 0 indica que está ocupada
int i, j;

inline bool sob_ataque(int lin, int col)
{
    // Não pode sair do tabuleiro
    if (lin < 1 || lin > 8 || col < 1 || col > 8)
        return true;
    //// Sendo atacado por um peão?
    if (tab[lin + 1][col - 1] == 'P' || tab[lin + 1][col + 1] == 'P')
        return true;
    //// Sendo atacado por um rei?
    if (tab[lin + 1][col - 1] == 'W' ||
            tab[lin + 1][col] == 'W' ||
            tab[lin + 1][col + 1] == 'W' ||
            tab[lin][col - 1] == 'W' ||
            tab[lin][col + 1] == 'W' ||
            tab[lin - 1][col - 1] == 'W' ||
            tab[lin - 1][col] == 'W' ||
            tab[lin - 1][col + 1] == 'W')
        return true;
    //// Horizontais (Torre e Rainha)
    // N
    i = lin + 1;
    while (i < 9 && !tab[i][col]) i++;
    if (tab[i][col] == 'T' || tab[i][col] == 'R')
        return true;
    // L
    j = col - 1;
    while (j > 0 && !tab[lin][j]) j--;
    if (tab[lin][j] == 'T' || tab[lin][j] == 'R')
        return true;
    // O
    j = col + 1;
    while (j < 9 && !tab[lin][j]) j++;
    if (tab[lin][j] == 'T' || tab[lin][j] == 'R')
        return true;
    // S
    i = lin - 1;
    while (i > 0 && !tab[i][col]) i--;
    if (tab[i][col] == 'T' || tab[i][col] == 'R')
        return true;
    //// Diagonais (Bispo e Rainha)
    // NO
    i = lin + 1; j = col - 1;
    while (i < 9 && j > 0 && !tab[i][j])
    {
        i++;
        j--;
    }
    if (tab[i][j] == 'B' || tab[i][j] == 'R')
        return true;
    // NE
    i = lin + 1; j = col + 1;
    while (i < 9 && j < 9 && !tab[i][j])
    {
        i++;
        j++;
    }
    if (tab[i][j] == 'B' || tab[i][j] == 'R')
        return true;
    // SO
    i = lin - 1; j = col - 1;
    while (i > 0 && j > 0 && !tab[i][j])
    {
        i--;
        j--;
    }
    if (tab[i][j] == 'B' || tab[i][j] == 'R')
        return true;
    // SE
    i = lin - 1; j = col + 1;
    while (i > 0 && j < 9 && !tab[i][j])
    {
        i--;
        j++;
    }
    if (tab[i][j] == 'B' || tab[i][j] == 'R')
        return true;
    return false;
}


int main()
{
    char peca;
    int col, lin;
    int pretas; // qtd de peças pretas
    while (scanf("%d ", &pretas) != EOF)
    {
        // Limpa tabuleiro
        memset(tab, 0, sizeof(tab));
        // Coloca as peças pretas no tabuleiro
        while (pretas--)
        {
            peca = getchar();     // P, T, B, R, W
            col = getchar() - 96; // 1 - 8
            lin = getchar() - 48; // 1 - 8
            getchar();            // pega espaco ou '\n'
            // A casa (lin,col) está ocupada pela peça atual
            tab[lin][col] = peca;
        }
        // Rei branco
        peca = getchar();
        col = getchar() - 96;
        lin = getchar() - 48;
        if (sob_ataque(lin - 1, col - 1) &&
                sob_ataque(lin - 1, col) &&
                sob_ataque(lin - 1, col + 1) &&
                sob_ataque(lin, col - 1) &&
                sob_ataque(lin, col) &&
                sob_ataque(lin, col + 1) &&
                sob_ataque(lin + 1, col - 1) &&
                sob_ataque(lin + 1, col) &&
                sob_ataque(lin + 1, col + 1))
            puts("SIM");
        else
            puts("NAO");
    }
    return 0;
}
