// ============================================================================
//
//       Filename:  01263-alliteration.cpp
//
//    Description:  URI 1263 - Alliteration
//
//        Version:  1.0
//        Created:  09/Nov/2012 16:01:41
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>


int main()
{
    char str[5200], *ptr;
    while (gets(str) != NULL)
    {
        int tam = strlen(str);
        std::transform(str, str + tam, str, ::tolower);
        ptr = str;
        char ini_ant = *ptr; // caractere inicial anterior
        char ini;
        int ans = 0;
        bool allit = false;
        while (*ptr != '\0')
        {
            if (*ptr == ' ')
            {
                ini = *(++ptr);
                if (ini == ini_ant && !allit) // !allit evita contar a mesma
                {
                    allit = true;
                    ans++;
                }
                else if (ini != ini_ant)
                    allit = false;
                ini_ant = ini;
            }
            ptr++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
