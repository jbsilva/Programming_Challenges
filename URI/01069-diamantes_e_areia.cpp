// ============================================================================
//
//       Filename:  01069-diamantes_e_areia.cpp
//
//    Description:  URI 1069 - Diamantes e Areia
//
//        Version:  1.0
//        Created:  13/Nov/2012 13:49:47
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


int main()
{
    char str[1001], *ptr;
    int cases, abre, diamantes;
    scanf("%d ", &cases);
    while (cases--)
    {
        gets(str);
        ptr = str;
        diamantes = abre = 0;
        while (*ptr != '\0')
        {
            if (*ptr == '<')
                abre++;
            else if (*ptr == '>' && abre > 0)
            {
                abre--;
                diamantes++;
            }
            ptr++;
        }
        printf("%d\n", diamantes);
    }
    return 0;
}
