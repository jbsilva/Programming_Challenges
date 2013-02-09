// ============================================================================
// 
//       Filename:  01303-spurs_rocks.cpp (URI)
// 
//    Description:  URI 1303 - Spurs Rocks
//                  IX maratona da USP: www.ime.usp.br/~cef/IXmaratona
//
//                  Obs.: Na maratona da USP a saída terminava com uma linha em
//                  branco, mas no URI isso causa Presentation Error.
// 
//        Version:  1.0
//        Created:  09/Feb/2013 13:43:27
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>

int pontos[101], recebidos[101], marcados[101];
struct time
{
    int id;
    double media;
};


inline int comp_time(const void* a, const void* b)
{
    if (pontos[((time*)a)->id] > pontos[((time*)b)->id])
        return -1;

    if (pontos[((time*)a)->id] < pontos[((time*)b)->id])
        return 1;

    if (((time*)a)->media > ((time*)b)-> media)
        return -1;

    if (((time*)a)->media < ((time*)b)-> media)
        return 1;

    // media[a] = media[b]
    if (marcados[((time*)a)->id] > marcados[((time*)b)->id])
        return -1;

    if (marcados[((time*)a)->id] < marcados[((time*)b)->id])
        return 1;

    if (((time*)a)->id < ((time*)b)->id)
        return -1;
    return 1;
}


int main()
{
    int qtd_times, partidas, t1, t2, p1, p2, instancia = 0;
    time times[101];

    while (scanf("%d", &qtd_times) && qtd_times)
    {
        memset(pontos, 0, sizeof(pontos));
        memset(recebidos, 0, sizeof(recebidos));
        memset(marcados, 0, sizeof(marcados));

        partidas = qtd_times * (qtd_times - 1) / 2;
        for (int i = 0; i < partidas; i++)
        {
            scanf("%d %d %d %d", &t1, &p1, &t2, &p2);

            if (p1 > p2)
            {
                pontos[t1] += 2;
                pontos[t2] += 1;
            }
            else
            {
                pontos[t2] += 2;
                pontos[t1] += 1;
            }

            marcados[t1] += p1;
            marcados[t2] += p2;
            recebidos[t1] += p2;
            recebidos[t2] += p1;
        }

        for (int i = 1; i <= qtd_times; i++)
        {
            if (recebidos[i] == 0) recebidos[i] = 1;

            times[i].id = i;
            times[i].media = (double)marcados[i]/recebidos[i];
        }

        qsort(&times[1], qtd_times, sizeof(time), comp_time);

        if (instancia) putchar('\n');
        printf("Instancia %d\n", ++instancia);

        for (int i = 1; i <= qtd_times; i++)
            printf("%d ", times[i].id);
        putchar('\n');
    }

    return 0;
}

