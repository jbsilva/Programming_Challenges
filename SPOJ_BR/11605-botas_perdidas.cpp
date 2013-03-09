// ============================================================================
//
//       Filename:  11605-botas_perdidas.cpp (SPOJ BR)
//                  01245-botas_perdidas.cpp (URI)
//
//    Description:  SPOJ BR 11605 - Botas Perdidas
//                  URI 1245 - Botas Perdidas
//                  Primeira fase da Maratona de Programação - 2011
//
//        Version:  1.0
//        Created:  11/Oct/2012 14:34:09
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int botas[31][2], qtd_botas, pares, num;
    char pe;
    while (scanf("%d", &qtd_botas) != EOF)
    {
        memset(botas, 0, sizeof(botas));
        for (int i = 0; i < qtd_botas; i++)
        {
            scanf("%d %c", &num, &pe);
            if (pe == 'E')
                botas[num - 30][0]++;
            else
                botas[num - 30][1]++;
        }
        pares = 0;
        for (int i = 0; i < 31; i++)
            pares += min(botas[i][0], botas[i][1]);
        printf("%d\n", pares);
    }
    return 0;
}
