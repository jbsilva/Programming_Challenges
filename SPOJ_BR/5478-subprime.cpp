// ============================================================================
//
//       Filename:  5478-subprime.cpp (SPOJ BR)
//                  01105-subprime.cpp (URI)
//
//    Description:  Primeira Fase da Maratona de Programação - 2009
//                  br.spoj.pl/problems/SUBPRIME/
//
//        Version:  1.0
//        Created:  09/16/2012 10:04:06 PM
//       Revision:  10/04/2012 00:05:00 AM
//                      Otimizei para conseguir 0.000s no URI
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int bancos, deb;
    int reserva[21];
    while (scanf("%d %d", &bancos, &deb) && (bancos || deb))
    {
        for (int i = 0; i < bancos; i++)
            scanf("%d", &reserva[i]);
        for (int i = 0; i < deb; i++)
        {
            int devedor, credor, valor;
            scanf("%d %d %d", &devedor, &credor, &valor);
            reserva[devedor - 1] -= valor;
            reserva[credor - 1] += valor;
        }
        bool possivel = true;
        for (int i = 0; i < bancos; i++)
            if (reserva[i] < 0)
            {
                possivel = false; break;
            }
        puts(possivel ? "S" : "N");
    }
    return 0;
}
