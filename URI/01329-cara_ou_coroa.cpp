// ============================================================================
//
//       Filename:  01329-cara_ou_coroa.cpp
//
//    Description:  URI 1329 - Cara ou Coroa
//
//        Version:  1.0
//        Created:  22/Apr/2013 23:46:34
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
    int N, r, joao, maria;

    while (scanf("%d", &N) && N)
    {
        joao = maria = 0;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &r);
            r ? joao++ : maria++;
        }

        printf("Mary won %d times and John won %d times\n", maria, joao);
    }

    return 0;
}

