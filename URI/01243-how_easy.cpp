// ============================================================================
// 
//       Filename:  01243-how_easy.cpp
// 
//    Description:  URI 1243 - How Easy
//                  O código ficou horrível, mas fiquei em 3o do ranking
// 
//        Version:  1.0
//        Created:  13/Oct/2012 19:08:45
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
    int tam, soma, qtd_pal, media;
    bool tem_ponto = false, palavra = true;

    soma = qtd_pal = tam = 0;
    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            if (palavra)
            {
                if (tem_ponto)
                    palavra = false;
                else
                    tam++;
            }
        }
        else if (c == '.')
        {
            if (tem_ponto)
                palavra = false;

            tem_ponto = true;
        }
        else if (c == ' ')
        {
            if (palavra && tam > 0)
            {
                soma += tam;
                qtd_pal++;
            }

            tam = 0;
            tem_ponto = false;
            palavra = true;
        }
        else if (c == '\n')
        {
            if (palavra && tam > 0)
            {
                soma += tam;
                qtd_pal++;
            }

            if (qtd_pal != 0)
            {
                media = soma/qtd_pal;
                if (media <= 3)
                    puts("250");
                else if (media <= 5)
                    puts("500");
                else
                    puts("1000");
            }
            else
                puts("250");

            soma = qtd_pal = tam = 0;
            tem_ponto = false;
            palavra = true;
        }
        else
            palavra = false;
    }

    return 0;
}
