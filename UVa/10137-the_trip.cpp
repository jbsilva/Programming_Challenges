// ============================================================================
//
//       Filename:  10137-the_trip.cpp (UVa)
//                  01220-the_trip.cpp (URI)
//
//    Description:  UVA 10137 - The Trip
//                  URI 1220 - The Trip
//
//                  A dificuldade deste problema está em lembrar que não se
//                  pode lidar com frações de centavos.
//
//        Version:  2.5
//        Created:  03/18/2011 03:35:39 AM
//       Revision:
//                  Versão 1.0:
//                      18/03/2011 -> Wrong Answer
//                  Versão 2.0:
//                      14/04/2011 -> Accepted
//                          Apenas mantive o modo de criar e armazenar o vetor
//                          "gastos"
//                  Versão 2.5:
//                      11/10/2012 -> Accepted
//                          Troquei iostream por cstdio, removi alocação
//                          dinâmica, troquei double por int
//
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int n, i, dolar, cents, gastos[1001], soma, rec, pag;
    double media;
    while (scanf("%d", &n) && n)
    {
        soma = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d.%d", &dolar, &cents);
            gastos[i] = 100 * dolar + cents;             // Passa para centavos
            soma += gastos[i];
        }
        media = (double)soma / n;                                // Gasto médio
        rec = pag = 0;
        for (i = 0; i < n; i++)
            if (gastos[i] > media)                          // Valor a ser pago
                pag += gastos[i] - media;
            else
                rec += media - gastos[i];               // Valor a ser recebido
        printf("$%.2lf\n", (pag > rec ? pag : rec) / 100.0);
    }
    return 0;
}
