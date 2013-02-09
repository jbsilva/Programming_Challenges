// ============================================================================
// 
//       Filename:  01301-produto_do_intervalo.cpp
// 
//    Description:  URI 1301 - Produto do Intervalo
// 
//        Version:  2.0 - TLE / Runtime Error
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
                int negativos = 0;
                bool zero = false;
                for (int j = n1; j <= n2 && !zero; j++)
                {
                    if (!seq[j])
                        zero = true;
                    else
                        //negativos += seq[j] >> (sizeof(int) * 8 - 1);
                        negativos += seq[j] >> 31;
                }

                if (zero)
                    putchar('0');
                else
                    putchar(negativos%2 ? '-' : '+');
            }
        }
        putchar('\n');
    }

    return 0;
}

