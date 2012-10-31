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

int main()
{
    int abre=0;
    char c, lixo[1001];
    while ((c=getchar()) != EOF)
    {
        if (c == '(')
            abre++;
        else if (c == ')')
        {
            abre--;
            if (abre < 0) // fechando parentese que nao foi aberto
            {
                //while ((c=getchar()) != '\n');
                gets(lixo);
                puts("incorrect");
                abre = 0;
            }
        }
        else if (c == '\n')
        {
            puts(abre == 0 ? "correct" : "incorrect");
            abre = 0;
        }
    }

    return 0;
}
