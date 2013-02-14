// ============================================================================
// 
//       Filename:  01209-festas_de_sao_petersburgo.cpp
// 
//    Description:  URI 1209 - Festas de São Petersburgo
// 
//        Version:  1.0 - TLE
//        Created:  14/Feb/2013 19:26:40
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int pessoas, relacoes, p1, p2;
    unsigned int min_amigos;
    set<int> g[1001];
    set<int>::iterator it;

    while (scanf("%d %d %u", &pessoas, &relacoes, &min_amigos) != EOF)
    {
        if (min_amigos == 0)
        {
            for (int i = 0; i < relacoes; i++)
                scanf("%d %d", &p1, &p2);

            putchar('1');
            for (int i = 2; i <= pessoas; i++)
                printf(" %d", i);
            putchar('\n');
        }
        else
        {
            for (int i = 0; i < relacoes; i++)
            {
                scanf("%d %d", &p1, &p2);
                g[p1].insert(p2);
                g[p2].insert(p1);
            }

            bool forever_alones = true; // Pessoas com menos de min_amigos
            while (forever_alones)
            {
                forever_alones = false;

                for (int i = 1; i <= pessoas; i++)
                    if (!g[i].empty() && g[i].size() < min_amigos)
                    {
                        forever_alones = true;

                        for (it = g[i].begin(); it != g[i].end(); ++it)
                            g[*it].erase(i);

                        g[i].clear();
                    }
            }

            // Imprime todos os que sobraram
            bool imprimiu = false;

            for (int i = 1; i <= pessoas; i++)
                if (!g[i].empty())
                {
                    if (!imprimiu)
                    {
                        imprimiu = true;
                        printf("%d", i);
                    }
                    else
                        printf(" %d", i);

                    // Limpa set para próximo input
                    g[i].clear();
                }

            if (imprimiu)
                putchar('\n');
            else
                puts("0");
        }
    }

    return 0;
}

