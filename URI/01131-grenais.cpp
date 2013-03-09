// ============================================================================
//
//       Filename:  01131-grenais.cpp
//
//    Description:  URI 1131 - Grenais
//
//        Version:  1.0
//        Created:  09/30/2012 02:49:40 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int gremio, inter, grenais = 0, vitorias_g = 0, vitorias_i = 0, empates = 0;
    char rep = '1';
    while (rep == '1')
    {
        grenais++;
        scanf("%d %d ", &inter, &gremio);
        if (gremio > inter)
            vitorias_g++;
        else if (inter > gremio)
            vitorias_i++;
        else
            empates++;
        do
        {
            puts("Novo grenal (1-sim 2-nao)");
            scanf("%c ", &rep);
        }
        while (rep != '1' && rep != '2');
    }
    printf("%d grenais\n", grenais);
    printf("Inter:%d\n", vitorias_i);
    printf("Gremio:%d\n", vitorias_g);
    printf("Empates:%d\n", empates);
    if (vitorias_g > vitorias_i)
        puts("Gremio venceu mais");
    else if (vitorias_i > vitorias_g)
        puts("Inter venceu mais");
    else
        puts("Nao houve vencedor");
    return 0;
}
