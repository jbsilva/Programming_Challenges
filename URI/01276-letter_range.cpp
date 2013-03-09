// ============================================================================
//
//       Filename:  01276-letter_range.cpp
//
//    Description:  URI 1276 - Letter Range
//                  Adaptada do topcoder por mim
//                  Não deve ser a melhor solução, mas é rapida o suficiente
//
//        Version:  1.0
//        Created:  17/Nov/2012 21:57:22
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
    int i, inicio, fim;
    char str[51], *ptr;
    bool aparece[27]; // Letra de 'a' a 'z' aparece na string?
    while (gets(str) != NULL)
    {
        memset(aparece, 0, sizeof(aparece));
        ptr = str;
        while (*ptr != '\0')
        {
            if (*ptr != ' ')
                aparece[*ptr - 'a'] = true;
            ptr++;
        }
        bool primeiro = true;
        i = 0;
        while (i < 26)
        {
            while (i < 26 && !aparece[i])
                i++;
            if (i != 26)
            {
                inicio = fim = i;
                while (i < 26 && aparece[i])
                    fim = i++;
                if (!primeiro) printf(", ");
                printf("%c:%c", 'a' + inicio, 'a' + fim);
                primeiro = false;
            }
        }
        putchar('\n');
    }
    return 0;
}
