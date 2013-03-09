// ============================================================================
//
//       Filename:  12487-midnight_cowboy.cpp (UVa)
//                  01227-perdido_na_noite.cpp (URI)
//
//    Description:  Maratona de Programação da SBC 2012
//                  URI 1227 - Perdido na Noite
//                  UVa 12487 - Midnight Cowboy
//
//                  Cadeia de Markov.
//                  Código baseado na minha solução do problema da 1a fase da
//                  maratona de 2008: SPOJ BR 3246 - Vampiros.
//                  Existem formas mais eficientes de ser resolvido.
//
//        Version:  1.0
//        Created:  24/Feb/2013 19:23:25
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

typedef struct
{
    double m[101][101];
} M101x101;

int N; // Quantidade de rotatórias = Dimensão da matrix de transição

// Multiplica matrizes 101x101: a*b = c
// TODO: trocar por Strassen
M101x101 m_mul(M101x101 a, M101x101 b)
{
    M101x101 c;
    memset(c.m, 0, sizeof(c.m));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 1; k <= N; k++)
                c.m[i][j] += a.m[i][k] * b.m[k][j];
    return c;
}

// Retorna a^n = b.
// Não precisa tratar n=0.
M101x101 m_exp(M101x101 a, int n)
{
    M101x101 b;
    if (n == 1)
        return a;
    else if (n % 2 == 0)
    {
        b = m_exp(a, n / 2);
        b = m_mul(b, b);
        return b;
    }
    else
    {
        b = m_exp(a, (n - 1) / 2);
        b = m_mul(b, b);
        return (m_mul(b, a));
    }
}


int main()
{
    int A, B, C; // A=aniversário, B=barato, C=caro
    int x, y;
    int grau[101];
    M101x101 mt; // Matriz de transição
    while (scanf("%d %d %d %d", &N, &A, &B, &C) != EOF)
    {
        memset(mt.m, 0, sizeof(mt.m));
        memset(grau, 0, sizeof(grau));
        for (int i = 1; i < N; i++)
        {
            scanf("%d %d", &x, &y);
            grau[x]++; grau[y]++;
            mt.m[x][y] = mt.m[y][x] = 1.0;
        }
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (mt.m[i][j])
                    mt.m[i][j] = 1.0 / grau[i];
        // m[B][B]=1 e o resto da linha fica 0. O mesmo vale para a linha C
        memset(mt.m[B], 0, (N + 1)*sizeof(double)); mt.m[B][B] = 1.0;
        memset(mt.m[C], 0, (N + 1)*sizeof(double)); mt.m[C][C] = 1.0;
        mt = m_exp(mt, 10000);
        // A resposta é a chance de sair de A e chegar em B = m[A][B]
        printf("%.6f\n", mt.m[A][B]);
    }
    return 0;
}

