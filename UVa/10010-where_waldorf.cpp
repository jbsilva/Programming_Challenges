// ============================================================================
//
//       Filename:  10010-where_waldorf.cpp
//
//    Description:  UVa 10010 - Where's Waldorf
//                  GOTO S2 S2 =P
//
//                  A troca do iostream pelo cstdio não reduziu o tempo
//
//        Version:  2.0
//        Created:  03/25/2011 03:26:13 PM -> WA
//       Revision:  09/24/2012 03:30:00 AM -> AC
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

int lins, cols;
string pal; // palavra procurada
int tam;
char grid[52][52];

inline bool find(int l, int c)
{
    // Noroeste
    if (l - tam >= 0 && c - tam >= 0)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l - i][c - i])
                goto N;
        goto ACHOU;
    }
N:  // Norte
    if (l - tam >= 0)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l - i][c])
                goto NE;
        goto ACHOU;
    }
NE: // Nordeste
    if (l - tam >= 0 && c + tam - 1 <= cols)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l - i][c + i])
                goto O;
        goto ACHOU;
    }
O:  // Oeste
    if (c - tam >= 0)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l][c - i])
                goto L;
        goto ACHOU;
    }
L:  // Leste
    if (c + tam - 1 <= cols)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l][c + i])
                goto SO;
        goto ACHOU;
    }
SO: // Sudoeste
    if (l + tam - 1 <= lins && c - tam >= 0)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l + i][c - i])
                goto S;
        goto ACHOU;
    }
S:  // Sul
    if (l + tam - 1 <= lins)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l + i][c])
                goto SE;
        goto ACHOU;
    }
SE: // Sudeste
    if (l + tam - 1 <= lins && c + tam - 1 <= cols)
    {
        for (int i = 0; i < tam; i++)
            if (pal.at(i) != grid[l + i][c + i])
                goto NAO_ACHOU;
        goto ACHOU;
    }
NAO_ACHOU:
    return false;
ACHOU:
    printf("%d %d\n", l, c);
    return true;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d %d", &lins, &cols);
        for (int i = 1; i <= lins; i++)
            scanf("%s", grid[i] + 1);
        for (int i = 1; i <= lins; i++)
            for (int j = 1; j <= cols; j++)
                grid[i][j] = tolower(grid[i][j]);
        int qtd_palavras;
        scanf("%d", &qtd_palavras);
        for (int i = 0; i < qtd_palavras; i++)
        {
            // Lê palavra e passa para minúsculas
            cin >> pal;
            transform(pal.begin(), pal.end(), pal.begin(), ::tolower);
            tam = pal.length();
            for (int l = 1; l <= lins; l++)
                for (int c = 1; c <= cols; c++)
                    if (find(l, c))
                        goto PROXIMO;
PROXIMO:
        }
        if (cases)
            printf("\n");
    }
    return 0;
}
