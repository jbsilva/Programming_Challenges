// ============================================================================
//
//       Filename:  01094-experiencias.cpp
//
//    Description:  URI 1094 - Experiências
//
//        Version:  1.0
//        Created:  09/30/2012 12:16:07 AM
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
    char tipo;
    int qtd, total = 0, ratos = 0, coelhos = 0, sapos = 0;
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d %c", &qtd, &tipo);
        total += qtd;
        switch (tipo)
        {
            case 'C': coelhos += qtd; break;
            case 'R': ratos += qtd; break;
            case 'S': sapos += qtd; break;
        }
    }
    printf("Total: %d cobaias\n"
           "Total de coelhos: %d\n"
           "Total de ratos: %d\n"
           "Total de sapos: %d\n"
           "Percentual de coelhos: %.2lf %%\n"
           "Percentual de ratos: %.2lf %%\n"
           "Percentual de sapos: %.2lf %%\n", total, coelhos, ratos, sapos,
           100.0 * coelhos / total, 100.0 * ratos / total, 100.0 * sapos / total);
    return 0;
}
