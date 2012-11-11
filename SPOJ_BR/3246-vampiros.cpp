// ============================================================================
// 
//       Filename:  3246-vampiros.cpp (SPOJ BR)
//                  01093-vampiros.cpp (URI)
// 
//    Description:  SPOJ BR 3246 - Vampiros
//                  URI 1093 - Vampiros
//
//                  Primeira fase da Maratona de Programação - 2008
//                  br.spoj.pl/problems/VAMPIROS/
//
//                  Aqui usei cadeias de Markov, mas existem métodos mais
//                  eficientes para resolver este problema.
//                  Procurar por Gambler's ruin.
// 
//        Version:  1.0
//        Created:  09/Nov/2012 23:42:11
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>

typedef struct{ double m[21][21]; } M21x21;

int _max;

// Multiplica matrizes 20x20: a*b = c
// TODO: trocar por Strassen
M21x21 m_mul(M21x21 a, M21x21 b, int tam =_max+1)
{
    M21x21 c;
    memset(c.m, 0, sizeof(c.m));

    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            for (int k = 0; k < tam; k++)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
    return c;
}

// Retorna a^n = b.
// Não precisa tratar n=0.
M21x21 m_exp(M21x21 a, int n)
{
    M21x21 b;

    if (n == 1)
        return a;
    else if (n%2 == 0)
    {
        b = m_exp(a, n/2);
        b = m_mul(b, b);
        return b;
    }
    else
    {
        b = m_exp(a,(n-1)/2);
        b = m_mul(b, b);
        return (m_mul(b, a));
    }
}


int main()
{
    int ev1, ev2, at, d;
    M21x21 mt; // Matriz de transição

    while (scanf("%d %d %d %d", &ev1, &ev2, &at, &d) && (ev1 || ev2 || at || d))
    {
        ev1 = 1 + (ev1 - 1) / d; // ceil
        ev2 = 1 + (ev2 - 1) / d; // ceil
        d = 1;

        double pg = at/6.0; // probabilidade de ganho
        double pp = 1 - pg; // probabilidade de perda
        _max = ev1 + ev2; // Energia vital final do ganhador

        memset(mt.m, 0, sizeof(mt.m));
        mt.m[0][0] = 1.0; mt.m[_max][_max] = 1.0;
        for (int i = 1; i < _max; i++)
            mt.m[i][i-1] = pp, mt.m[i][i+1] = pg;

        mt = m_exp(mt, 1000);

        printf("%.1f\n", 100*mt.m[ev1][_max]);
    }

    return 0;
}
