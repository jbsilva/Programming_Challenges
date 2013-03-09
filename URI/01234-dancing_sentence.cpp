// ============================================================================
//
//       Filename:  01234-dancing_sentence.cpp
//
//    Description:  URI 1234 - Dancing Sentence
//
//        Version:  1.0
//        Created:  10/05/2012 10:32:24 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cctype>

int main()
{
    char c;
    bool upper = false;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            putchar(' ');
        else if (c == '\n')
        {
            putchar('\n');
            upper = false; // Para a próxima sentença começar com uma maiúscula
        }
        else if ((upper = !upper))
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
    return 0;
}
