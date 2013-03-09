// ============================================================================
//
//       Filename:  01287-friendly_int_parser.cpp
//
//    Description:  URI 1287 - Friendly Int Parser
//                  Adaptado do TopCoder por mim
//
//        Version:  1.0
//        Created:  14/Dec/2012 09:08:08
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cstdlib>

char str[51], *ptr_in, *ptr_out;

inline bool overflow()
{
    int tam = strlen(str);
    if (tam < 10)
        return false;
    if (tam > 10)
        return true;
    if (strcmp(str, "2147483647") > 0)
        return true;
    return false; // nunca chega aqui
}


int main()
{
    while (gets(str) != NULL)
    {
        bool erro = false;
        ptr_in = ptr_out = str;
        // Remove zeros à esquerda
        while (*ptr_in == '0')
            ptr_in++;
        // Era tudo zero (e não string vazia)?
        if (*ptr_out != '\0' && *ptr_in == '\0')
            *ptr_out = '0', *(++ptr_out) = '\0';
        while (*ptr_in != '\0')
        {
            if (*ptr_in >= '0' && *ptr_in <= '9')
            {
                *ptr_out = *ptr_in;
                ptr_out++;
            }
            else if (*ptr_in == 'o' || *ptr_in == 'O')
            {
                *ptr_out = '0';
                ptr_out++;
            }
            else if (*ptr_in == 'l')
            {
                *ptr_out = '1';
                ptr_out++;
            }
            else if (*ptr_in != ',' && *ptr_in != ' ')
            {
                erro = true;
                break;
            }
            ptr_in++;
        }
        *ptr_out = '\0';
        // Verifica se daria overflow
        if (!erro && (strlen(str) == 0 || overflow()))
            erro = true;
        if (erro)
            puts("error");
        else
            printf("%ld\n", strtol(str, NULL, 10));
    }
    return 0;
}
