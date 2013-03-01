// ============================================================================
// 
//       Filename:  10815-andys_first_dictionary.cpp (UVa)
//                  01215-andys_first_dictionary.cpp (URI)
// 
//    Description:  UVa 10815 - Andy's first Dictionary
//                  URI 1215 - Andy's first Dictionary
// 
//        Version:  1.0 - Runtime Error
//        Created:  28/Feb/2013 21:01:17
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>


inline int comp_str_ptr(const void *a, const void *b)
{
    return strcmp(*(char* const*)a, *(char* const*)b);
}


int main()
{
    char words[20001][202], lin[202], *ptrs[20001], *ptr;
    int qtd = -1;
    while (gets(lin) != NULL)
    {
        // Meu strtok personalizado
        int i = 0;
        bool anterior_letra = false;
        ptr = lin;
        while (*ptr != '\0')
        {
            if (('a' <= *ptr && *ptr <= 'z') || ('A' <= *ptr && *ptr <= 'Z'))
            {
                if (!anterior_letra)
                {
                    qtd++;
                    i = 0;
                    ptrs[qtd] = words[qtd];
                }
                words[qtd][i++] = (*ptr < 'a') ? *ptr+32 : *ptr;
                anterior_letra = true;
            }
            else
            {
                if (anterior_letra)
                    words[qtd][i] = '\0';
                anterior_letra = false;
            }

            ptr++;
        }
        // Para quando a linha tiver exatamente 200 chars e terminar numa letra
        if (anterior_letra)
            words[qtd][i] = '\0';
    }

    qsort(ptrs, qtd+1, sizeof(char*), comp_str_ptr);

    puts(ptrs[0]);
    for (int i = 1; i <= qtd; i++)
        if (strcmp((char const*)ptrs[i-1], (char const*)ptrs[i]))
            puts(ptrs[i]);

    return 0;
}

