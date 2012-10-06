// ============================================================================
// 
//       Filename:  8305-leitura_otica.cpp (SPOJ BR)
//                  01129-leitura_otica.cpp (URI)
//                  11839-optical_reader.cpp (UVa)
// 
//    Description:  Primeira fase da Maratona de Programação - 2010
// 
//        Version:  1.0
//        Created:  08/12/2012 01:17:44 PM
//       Revision:  06/10/2012 00:04:00 AM
//                      Troquei iostream por cstdio
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

int main()
{
    int qtd_quest, qtd_marcada, marcada;
    int i, j, resp;

    const char letra[] = {'A', 'B', 'C', 'D', 'E'};

    scanf("%d", &qtd_quest);
    while (qtd_quest)
    {
        for (i=0; i<qtd_quest; i++)
        {
            qtd_marcada = 0;
            for (j=0; j < 5; j++)
            {
                scanf("%d", &resp);
                if (resp <= 127)
                {
                    marcada = j;
                    qtd_marcada++;
                }
            }

            if (qtd_marcada != 1)
                puts("*");
            else
                printf("%c\n", letra[marcada]);
        }

        scanf("%d", &qtd_quest);
    }

    return 0;
}
