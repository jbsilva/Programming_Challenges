// ============================================================================
//
//       Filename:  01367-ajude.cpp
//
//    Description:  URI 1367 - Ajude!
//
//        Version:  1.0
//        Created:  08/May/2013 21:35:50
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int main()
{
    int N, pena_letra[27];
    while (scanf("%d", &N) && N)
    {
        char problema, julgamento[20];
        int acertos = 0, tempo, penalidade = 0;
        memset(pena_letra, 0, sizeof(pena_letra));
        for (int i = 0; i < N; i++)
        {
            scanf(" %c %d %s", &problema, &tempo, julgamento);
            if (julgamento[0] == 'c')
            {
                acertos++;
                penalidade += tempo + pena_letra[problema - 'A'];
            }
            else
                pena_letra[problema - 'A'] += 20;
        }
        printf("%d %d\n", acertos, penalidade);
    }
    return 0;
}

