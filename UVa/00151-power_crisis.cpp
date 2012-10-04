// ============================================================================
// 
//       Filename:  00151-power_crisis.cpp (UVa)
//                  01031-power_crisis.cpp (URI)
// 
//    Description:  UVa 151 - Power Crisis
//                  URI 1031 - Power Crisis
//
//                  O Josephus Problem tem a seguinte recorrência:
//                  J(1,m) = 0; J(n,m) = (J(n-1,m) + m) % n;
//
//        Version:  1.0
//        Created:  10/02/2012 10:54:16 PM
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
    int qtd_regioes;
    while (scanf("%d", &qtd_regioes) && qtd_regioes)
    {
        for (int m=1; ; m++)                    // Nunca entra em loop infinito
        {
            int n = qtd_regioes;                           // Regiões restantes
            int atual = 0;                   // Primeira região a ser desligada
            int c13 = 12;                  // Posição da região 13 (Wellington)
            while (atual != c13)
            {
                if (atual < c13)
                    c13--;
                n--;
                //printf("Desligando #%d. Sobraram %d\n", atual, n);
                atual = (atual-1 + m) % n;
            }

            if (n == 1)                               // Só sobrou a cidade 13?
            {
                printf("%d\n", m);
                break;
            }
        }
    }

    return 0;
}
