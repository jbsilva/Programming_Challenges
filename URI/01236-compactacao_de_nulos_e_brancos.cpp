// ============================================================================
//
//       Filename:  01236-compactacao_de_nulos_e_brancos.cpp
//
//    Description:  URI 1236 - Compactação de Nulos e Brancos
//
//        Version:  1.0
//        Created:  13/Dec/2012 08:24:57
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
    int cases, reps;
    char line[2001], *ptr;
    scanf("%d ", &cases);
    while (cases--)
    {
        gets(line);
        ptr = line;
        while (*ptr != '\0')
        {
            reps = 0;
            while (*ptr == '0')
            {
                reps++; ptr++;
            }
            if (reps == 1) putchar('0');
            else if (reps == 2) fputs("00", stdout);
            else if (reps)
            {
                while (reps > 255)
                {
                    printf("#%c", (char)255);
                    reps -= 255;
                }
                if (reps)
                    printf("#%c", (char)reps);
            }
            reps = 0;
            while (*ptr == ' ')
            {
                reps++; ptr++;
            }
            if (reps == 1) putchar(' ');
            else if (reps == 2) fputs("  ", stdout);
            else if (reps)
            {
                while (reps > 255)
                {
                    printf("$%c", (char)255);
                    reps -= 255;
                }
                if (reps)
                    printf("$%c", (char)reps);
            }
            if (*ptr != '0' && *ptr != '\0')
            {
                putchar(*ptr);
                ptr++;
            }
        }
        putchar('\n');
    }
    return 0;
}
