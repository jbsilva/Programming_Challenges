// ============================================================================
// 
//       Filename:  01301-produto_do_intervalo.cpp
// 
//    Description:  URI 1301 - Produto do Intervalo
// 
//        Version:  1.0 - TLE
//        Created:  09/Feb/2013 01:34:43
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
    int elems, rodadas, seq[100001], n1, n2;

    while (scanf("%d %d", &elems, &rodadas) != EOF)
    {
        for (int i = 1; i <= elems; i++)
            scanf("%d ", &seq[i]);

        char c;
        for (int i = 0; i < rodadas; i++)
        {
            scanf("%c %d %d ", &c, &n1, &n2);

            if (c == 'C')
                seq[n1] = n2;
            else
            {
                int produto = 1;
                for (int j = n1; j <= n2 && produto; j++)
                    produto *= (seq[j] > 0) - (seq[j] < 0);

                if (produto)
                    putchar(produto < 0 ? '-' : '+');
                else
                    putchar('0');
            }
        }
        putchar('\n');
    }

    return 0;
}

