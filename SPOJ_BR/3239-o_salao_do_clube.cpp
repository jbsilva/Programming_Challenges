// ============================================================================
//
//       Filename:  3239-o_salao_do_clube.cpp (SPOJ BR)
//                  11493-the_club_ballroom.cpp (UVa)
//                  01086-o_salao_do_clube.cpp (URI)
//
//    Description:  SPOJ BR 3239 - O Salão do Clube
//                  UVa 11493 - The Club Ballroom
//                  URI 1086 - O Salão do Clube
//
//                  Primeira fase da Maratona de Programação - 2008
//                  br.spoj.com/problems/CLUBE/
//
//                  TODO: Otimizar o `while` que tem um `tam--`.  Pode ser
//                        trocado por um set que evite verificar tamanhos que
//                        não existem.
//
//        Version:  1.0
//        Created:  17/Jul/2013 20:11:23
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


#define INF 0x3f3f3f3f


int main()
{
    int M, N, L, K, tabua[10001]; // tabua[i]: número de tábuas com tamanho i
    while (scanf("%d %d", &M, &N) && (M || N))
    {
        scanf("%d %d", &L, &K);

        // Inicia com 0 tábuas de cada tamanho
        memset(tabua, 0, sizeof(tabua));

        for (int i = 0; i < K; i++)
        {
            int tam;
            scanf("%d", &tam);
            tabua[tam]++;
        }

        bool possivel = false;

        // Tábuas na vertical
        int usado_v = INF;
        if (100 * M % L == 0)
        {
            // Número de colunas faltando para completar
            int col_falta = 100 * M / L;
            usado_v = 0;
            // Tábuas de tamanho exato
            usado_v += min(col_falta, tabua[N]);
            col_falta -= usado_v;
            // Pares
            int tam = N - 1;
            while (col_falta && tam > N / 2)
            {
                int pares = min(tabua[tam], tabua[N - tam]);
                usado_v += 2 * min(col_falta, pares);
                col_falta -= min(col_falta, pares);
                tam--;
            }
            // Tábuas de tamanho N/2
            if (col_falta && (N % 2 == 0))
            {
                int pares = tabua[N / 2] / 2;
                usado_v += 2 * min(col_falta, pares);
                col_falta -= min(col_falta, pares);
            }
            if (!col_falta)
                possivel = true;
            else
                usado_v = INF; // Para podar usar o min depois
        }

        // Tábuas na horizontal
        int usado_h = INF;
        if (100 * N % L == 0)
        {
            // Número de colunas faltando para completar
            int col_falta = 100 * N / L;
            usado_h = 0;
            // Tábuas de tamanho exato
            usado_h += min(col_falta, tabua[M]);
            col_falta -= usado_h;
            // Pares
            int tam = M - 1;
            while (col_falta && tam > M / 2)
            {
                int pares = min(tabua[tam], tabua[M - tam]);
                usado_h += 2 * min(col_falta, pares);
                col_falta -= min(col_falta, pares);
                tam--;
            }
            // Tábuas de tamanho M/2
            if (col_falta && (M % 2 == 0))
            {
                int pares = tabua[M / 2] / 2;
                usado_h += 2 * min(col_falta, pares);
                col_falta -= min(col_falta, pares);
            }
            if (!col_falta)
                possivel = true;
            else
                usado_h = INF; // Para podar usar o min depois
        }

        if (possivel)
            printf("%d\n", min(usado_v, usado_h));
        else
            puts("impossivel");
    }
    return 0;
}

