// ============================================================================
//
//       Filename:  8302-elevador.cpp (SPOJ BR)
//                  11834-elevator.cpp (UVa)
//                  01124-elevador.cpp (URI)
//
//    Description:  Primeira fase da Maratona de Programação - 2010
//                  br.spoj.com/problems/ELEVADOR/
//
//                  Se o diâmetro de cada círculo for menor ou igual à menor
//                  dimensão do retângulo, tentar colocar um círculo em um
//                  canto e o outro no canto oposto do retângulo, depois
//                  verificar se a distância entre seus centros é maior que a
//                  soma de seus raios (para não ter sobreposição).
//
//        Version:  1.0
//        Created:  03/Feb/2013 23:34:37
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int larg, comp, r1, r2;
    while (scanf("%d %d %d %d", &larg, &comp, &r1, &r2) && (larg || comp))
    {
        int menor = larg < comp ? larg : comp;
        if (2 * r1 <= menor && 2 * r2 <= menor)
        {
            if (hypot(larg - r2 - r1, comp - r2 - r1) >= r1 + r2)
                puts("S");
            else
                puts("N");
        }
        else
            puts("N");
    }
    return 0;
}

