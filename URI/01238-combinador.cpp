// ============================================================================
// 
//       Filename:  01238-combinador.cpp
// 
//    Description:  URI 1238 - Combinador / Combiner
// 
//        Version:  1.0
//        Created:  10/04/2012 04:05:46 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    char a[55], b[55];
    int tam_a, tam_b;

    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%s %s", a, b);
        tam_a = strlen(a);
        tam_b = strlen(b);

        if (tam_a < tam_b)
        {
            for (int i=0; i < tam_a; i++)
                printf("%c%c", a[i], b[i]);
            printf("%s", b+tam_a);
        }
        else
        {
            for (int i=0; i < tam_b; i++)
                printf("%c%c", a[i], b[i]);
            printf("%s", a+tam_b);  // Se tam_a == tam_b, não vai imprimir nada
        }
        putchar('\n');
    }

    return 0;
}
