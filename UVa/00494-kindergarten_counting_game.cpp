// ============================================================================
//
//       Filename:  00494-kindergarten_counting_game.cpp
//
//    Description:  UVa Kindergarten Counting Game
//
//        Version:  1.0
//        Created:  10/01/2012 08:36:06 PM
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
    int count = 0;
    register char c;
    bool word = false;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))             // Só é palavra se tiver letra
            word = true;
        else if (c == '\n')         // Terminou a linha de input
        {
            if (word)
                count++;
            printf("%d\n", count);
            word = false;
            count = 0;
        }
        else                        // Todos os caracteres devem ser letras
        {
            // pela definição de palavra do enunciado.
            if (word)               // "Batata123frita! ..." são duas palavras
                count++;
            word = false;
        }
    }
    return 0;
}
