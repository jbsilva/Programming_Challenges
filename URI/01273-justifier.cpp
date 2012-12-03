// ============================================================================
// 
//       Filename:  01273-justifier.cpp
// 
//    Description:  URI 1273 - Justifier
// 
//        Version:  1.0
//        Created:  03/Dec/2012 12:38:17
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
    char p[51][51];
    int tam[51], maior, i;

    int n, caso = 0;
    while (scanf("%d ", &n) && n)
    {
        if (caso++) putchar('\n');

        maior = 0;
        for (i = 0; i < n; i++)
        {
            gets(p[i]);
            tam[i] = strlen(p[i]);
            if (tam[i] > maior)
                maior = tam[i];
        }

        for (i = 0; i < n; i++)
        {
            for (int j = 0; j < maior - tam[i]; j++)
                putchar(' ');

            puts(p[i]);
        }
    }

    return 0;
}
