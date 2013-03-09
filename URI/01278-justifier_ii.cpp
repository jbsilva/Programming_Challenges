// ============================================================================
//
//       Filename:  01278-justifier_ii.cpp
//
//    Description:  URI 1278 - Justifier II
//
//        Version:  1.0
//        Created:  03/Dec/2012 23:24:31
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
    char p[101][52], line[52], *ptr1, *ptr2;
    int tam[101], maior, i, offset;
    int n, caso = 0;
    while (scanf("%d ", &n) && n)
    {
        if (caso++) putchar('\n');
        maior = 0;
        for (i = 0; i < n; i++)
        {
            gets(line);
            ptr1 = line;
            ptr2 = p[i];
            // Preenche array p[i]
            while (sscanf(ptr1, "%s%n", ptr2, &offset) != EOF)
            {
                ptr1 += offset;
                ptr2 += strlen(ptr2); *ptr2 = ' '; ptr2++;
            }
            *(--ptr2) = '\0'; // Depois da última palavra não tem espaço
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

