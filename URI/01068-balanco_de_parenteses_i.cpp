// ============================================================================
//
//       Filename:  01068-balanco_de_parenteses_i.cpp
//
//    Description:  URI 1068 - Balanço de Parênteses I
//
//        Version:  1.0
//        Created:  31/Oct/2012 21:32:00
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
    int abre;
    char exp[1001], *ptr;
    while (gets(exp) != NULL)
    {
        abre = 0;
        ptr = exp;
        while (*ptr != '\0')
        {
            if (*ptr == '(')
                abre++;
            else if (*ptr == ')')
            {
                abre--;
                if (abre < 0)
                    break;
            }
            ptr++;
        }
        puts(abre ? "incorrect" : "correct");
    }
    return 0;
}
