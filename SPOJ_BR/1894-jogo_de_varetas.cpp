// ============================================================================
//
//       Filename:  1894-jogo_de_varetas.cpp (SPOJ BR)
//                  01366-jogo_de_varetas.cpp (URI)
//
//    Description:  SPOJ BR 1894 - Jogo de Varetas
//                  URI 1366 - Jogo de Varetas
//
//                  br.spoj.pl/problems/VARETAS/
//                  Primeira fase da Maratona de Programação - 2007
//
//        Version:  1.0
//        Created:  09/13/2012 10:03:47 PM
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
    int n; // número de diferentes comprimentos
    while (scanf("%d", &n) && n)
    {
        int soma_pares = 0;
        for (int i = 0; i < n; i++)
        {
            int tam, qtd;
            scanf("%d %d", &tam, &qtd);
            soma_pares += qtd / 2;
        }
        printf("%d\n", soma_pares / 2);
    }
    return 0;
}

