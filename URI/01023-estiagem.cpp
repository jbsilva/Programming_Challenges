// ============================================================================
//
//       Filename:  01023-estiagem.cpp
//
//    Description:  URI 1023 - Estiagem
//
//        Version:  1.0
//        Created:  19/Oct/2012 18:53:42
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;


int main()
{
    int imoveis, moradores, consumo, tot_moradores, tot_consumo, cidade = 0;
    map<int, int> consumos;
    map<int, int>::iterator it;
    while (scanf("%d", &imoveis) && imoveis)
    {
        if (cidade) putchar('\n');
        printf("Cidade# %d:\n", ++cidade);
        tot_moradores = tot_consumo = 0;
        for (int i = 0; i < imoveis; i++)
        {
            scanf("%d %d", &moradores, &consumo);
            consumos[consumo / moradores] += moradores;
            tot_moradores += moradores;
            tot_consumo += consumo;
        }
        it = consumos.begin();
        printf("%d-%d", it->second, it->first);
        for (++it; it != consumos.end(); ++it)
            printf(" %d-%d", it->second, it->first);
        double medio = floor(100.0 * tot_consumo / tot_moradores) / 100;
        printf("\nConsumo medio: %.2lf m3.\n", medio);
        consumos.clear();
    }
    return 0;
}
