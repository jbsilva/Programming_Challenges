// ============================================================================
//
//       Filename:  01309-monetary_formatting.cpp
//
//    Description:  URI 1309 - Monetary Formatting
//
//        Version:  1.0
//        Created:  09/Apr/2013 20:57:52
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
    char dolar[300];
    int cents, tam, sobra, i;

    while (gets(dolar) != NULL)
    {
        scanf("%d ", &cents);
        tam = strlen(dolar);
        sobra = tam % 3;

        i = 0;
        putchar('$');

        if (tam > 3)
        {
            if (sobra == 1)
            {
                printf("%c", dolar[i]);
                i++;
            }
            else if (sobra == 2)
            {
                printf("%c%c", dolar[i], dolar[i+1]);
                i += 2;
            }
            else if (sobra == 0)
            {
                printf("%c%c%c", dolar[i], dolar[i+1], dolar[i+2]);
                i += 3;
            }

            while (i <= tam-3)
            {
                printf(",%c%c%c", dolar[i], dolar[i+1], dolar[i+2]);
                i += 3;
            }
            printf(".%02d\n", cents);
        }
        else
            printf("%s.%02d\n", dolar, cents);
    }

    return 0;
}

