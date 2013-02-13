// ============================================================================
// 
//       Filename:  12485-perfect_choir.cpp (UVa)
//                  01225-coral_perfeito.cpp (URI)
// 
//    Description:  Primeira Fase da Maratona de Programação 2012
//                  UVa 12485 - Perfect Choir
//                  URI 1225 - Coral Perfeito
// 
//        Version:  1.0
//        Created:  13/Feb/2013 18:32:33
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

int main()
{
    int N, notas[10001];

    while(scanf("%d", &N) != EOF)
    {
        int soma = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &notas[i]);
            soma += notas[i];
        }

        // A soma permanecerá constante, pois quando uma nota é incrementada
        // outra é decrementada. No final todas as notas terão valor F, então a
        // soma das notas será F*N = soma, que é múltiplo de N.
        if (soma % N)
            puts("-1");
        else
        {
            int F = soma/N;
            int diff;
            int compassos = 1;
            for (int i = 0; (diff = F - notas[i]) > 0; i++)
                compassos += diff;

            printf("%d\n", compassos);
        }
    }

    return 0;
}

