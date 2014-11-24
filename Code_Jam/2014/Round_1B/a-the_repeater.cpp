// ============================================================================
// 
//       Filename:  a-the_repeater.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  03/Mai/2014 18:02:48
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (342639), julio@juliobs.com
//        Company:  RWTH Aachen
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>


int main()
{
    int T, N, letra, qtd_letras, m[101][101], med[101];
    char ordem_letras[101], ordem_atual[101];

    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        memset(m, 0, sizeof(m));

        scanf("%d ", &N);

        bool perdeu = false;
        for (int i = 0; i < N; i++)
        {
            char c, pre = '\n';
            letra = -1;

            while ((c = getchar()) != '\n')
            {
                if (c != pre)
                {
                    letra++;
                    ordem_atual[letra] = c;
                }

                m[i][letra]++;
                pre = c;
            }

            if (i == 0)
            {
                qtd_letras = letra;

                for (int k = 0, k < qtd_letras; k++)
                    ordem_letras[k] = ordem_atual[k];
            }
            else if (letra != qtd_letras)
                perdeu = true;
            else
            {
                for (int k = 0, k < qtd_letras; k++)
                    if (ordem_letras[k] != ordem_atual[k])
                        perdeu = true;
            }
        }

        /*
        // Imprime matriz
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= letra; j++)
                printf("%2d", m[i][j]);
            putchar('\n');
        }
        */

        // Matriz media
        for (int j = 0; j <= letra; j++)
        {
            int sum = 0;
            for (int i = 0; i < N; i++)
                sum += m[i][j];

            med[j] = sum / N;
        }

        if (!perdeu)
        {
            int movs = 0;
            // Distancia
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j <= letra; j++)
                    if (m[i][j] > med[j])
                        movs += m[i][j] - med[j];
                    else
                        movs += med[j] - m[i][j];
            }

            printf("Case #%d: %d\n", caso, movs);
        }
        else
            printf("Case #%d: Fegla Won\n", caso);
    }

    return 0;
}
