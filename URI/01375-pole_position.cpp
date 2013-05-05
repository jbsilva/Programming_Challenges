// ============================================================================
//
//       Filename:  01375-pole_position.cpp
//
//    Description:  URI 1375 - Pole Position
//
//        Version:  1.0
//        Created:  05/May/2013 03:42:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int N, pole[1100];


bool le_verifica()
{
    int c, p;
    bool tudo_ok = true;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &c, &p);

        if (i+p < 0 || i+p >= N || pole[i+p])
            tudo_ok = false;
        else
            pole[i+p] = c;
    }

    return (tudo_ok ? true : false);
}


int main()
{
    while (scanf("%d", &N) && N)
    {
        memset(pole, 0, sizeof(pole));

        if (le_verifica())
        {
            printf("%d", pole[0]);
            for (int i = 1; i < N; i++)
                printf(" %d", pole[i]);
            putchar('\n');
        }
        else
            puts("-1");
    }

    return 0;
}

