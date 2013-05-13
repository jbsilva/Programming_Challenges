// ============================================================================
//
//       Filename:  10176-ocean_deep_make_it_shallow.cpp (UVa)
//                  01398-ocean_deep_make_it_shallow.cpp (URI)
//
//    Description:  UVa 10176 - Ocean Deep! Make it shallow!!
//                  URI 1398 - Ocean Deep! Make it shallow!!
//
//        Version:  1.0
//        Created:  12/May/2013 22:15:08
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
    char bin[10100], lin[200], *ptr;
    int tam = 0, mod;
    while (gets(lin) != NULL)
    {
        strcpy(bin + tam, lin);
        tam += strlen(lin);
        if (bin[tam - 1] == '#')
        {
            ptr = bin;
            mod = 0;
            while (*ptr != '#')
            {
                mod = ((mod << 1) | (*ptr == '1')) % 131071;
                ptr++;
            }
            puts(mod ? "NO" : "YES");
            // Próximo input sobrescreve o array atual
            tam = 0;
        }
    }
    return 0;
}

