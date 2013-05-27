// ============================================================================
//
//       Filename:  00439-knight_moves.cpp (UVa)
//                  01100-knight_moves.cpp (URI)
//
//    Description:  UVa 439 - Knight Moves
//                  URI 1100 - Knight Moves
//
//        Version:  1.0
//        Created:  26/May/2013 15:24:12
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


struct sqr
{
    int lin, col, lvl;

    inline bool operator==(const sqr &s) const
    {
        return (lin == s.lin && col == s.col);
    }
};

char ac, bc;
int al, bl;
sqr orig, dest, atual, prox;
bool visitado[65];


int bfs()
{
    queue<sqr> Q;
    Q.push(orig);
    if (orig == dest) return orig.lvl;
    visitado[orig.lin * 8 + orig.col] = 1;
    while (!Q.empty())
    {
        atual = Q.front(); Q.pop();
        if (atual.col >= 1 && atual.lin <= 5)
        {
            prox.lin = atual.lin + 2; prox.col = atual.col - 1;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col <= 6 && atual.lin <= 5)
        {
            prox.lin = atual.lin + 2; prox.col = atual.col + 1;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col >= 2 && atual.lin <= 6)
        {
            prox.lin = atual.lin + 1; prox.col = atual.col - 2;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col <= 5 && atual.lin <= 6)
        {
            prox.lin = atual.lin + 1; prox.col = atual.col + 2;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col >= 2 && atual.lin >= 1)
        {
            prox.lin = atual.lin - 1; prox.col = atual.col - 2;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col <= 5 && atual.lin >= 1)
        {
            prox.lin = atual.lin - 1; prox.col = atual.col + 2;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col >= 1 && atual.lin >= 2)
        {
            prox.lin = atual.lin - 2; prox.col = atual.col - 1;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
        if (atual.col <= 6 && atual.lin >= 2)
        {
            prox.lin = atual.lin - 2; prox.col = atual.col + 1;
            prox.lvl = atual.lvl + 1;
            if (prox == dest) return prox.lvl;
            if (!visitado[prox.lin * 8 + prox.col])
            {
                Q.push(prox);
                visitado[prox.lin * 8 + prox.col] = 1;
            }
        }
    }
    return 0; // Nunca chega aqui
}


int main()
{
    while (scanf("%c%d %c%d ", &ac, &al, &bc, &bl) != EOF)
    {
        memset(visitado, 0, sizeof(visitado));
        orig.lin = (al - 1); orig.col = (int)(ac - 'a'); orig.lvl = 0;
        dest.lin = (bl - 1); dest.col = (int)(bc - 'a'); dest.lvl = 0;
        printf("To get from %c%d to %c%d takes %d knight moves.\n",
               ac, al, bc, bl, bfs());
    }
    return 0;
}

