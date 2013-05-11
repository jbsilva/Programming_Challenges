// ============================================================================
//
//       Filename:  01397-jogo_do_maior.cpp
//
//    Description:  URI 1397 - Jogo do Maior
//
//        Version:  1.0
//        Created:  10/May/2013 19:58:46
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
    int N, a, b, p_a, p_b;
    while (scanf("%d", &N) && N)
    {
        p_a = p_b = 0;
        while (N--)
        {
            scanf("%d %d", &a, &b);

            if (a > b)
                p_a++;
            else if (b > a)
                p_b++;
        }
        printf("%d %d\n", p_a, p_b);
    }

    return 0;
}

