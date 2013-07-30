// ============================================================================
//
//       Filename:  00424-integer_inquiry.cpp
//
//    Description:  UVa 424 - Integer Inquiry
//
//        Version:  1.0
//        Created:  27/Jul/2013 13:24:22
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


#define MAX 105


int main()
{
    char soma[MAX], num[MAX];
    int tam, i = 0, j;

    memset(soma, 0, sizeof(soma));

    while (gets(num) && (num[0] != '0' || num[1] != '\0'))
    {
        tam = strlen(num);

        for (i = MAX-1, j = tam-1; j >= 0; i--, j--)
        {
            soma[i] += num[j] - '0';

            if (soma[i] > 9)
            {
                soma[i] %= 10;
                soma[i-1]++;
            }
        }

        // Trata o último carry
        if (soma[i] > 9)
        {
            soma[i] %= 10;
            soma[i-1]++;
        }
    }

    i = 0;
    while (!soma[i])
        i++;

    for (; i < MAX; i++)
        putchar(soma[i] + '0');
    putchar('\n');

    return 0;
}

