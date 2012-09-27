// ===================================================================
// 
//       Filename:  12482-short_story_competition.cpp
//                  01222-concurso_de_contos.cpp
// 
//    Description:  Problema A: Concurso de Contos
//                  Primeira Fase da Maratona de Programação 2012
//
//                  UVa 12482 - Short Story Competition
//                  URI 1222 - Concurso de Contos
// 
//        Version:  2.0
//        Created:  09/17/2012 04:52:15 PM
//       Revision:  Removi string, iostream e cmath para ficar mais rápido
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ===================================================================
#include <cstdio>
#include <cstring>

int main()
{
    int qtd_palavras, max_lin, max_char, tam, qtd_linhas, len, i;
    char p[72];
    while (scanf("%d %d %d", &qtd_palavras, &max_lin, &max_char) != EOF)
    {
        tam = qtd_linhas = 0;
        for (i=0; i < qtd_palavras; i++)
        {
            scanf("%s", p);
            len = strlen(p);

            tam += len + 1;

            if (tam > max_char+1)
            {
                qtd_linhas++;
                tam = len + 1;
            }
            
            if (tam == max_char || tam-1 == max_char)
            {
                qtd_linhas++;
                tam = 0;
            }
            else if (i == qtd_palavras-1)
                qtd_linhas++;
        }

        printf("%d\n", (qtd_linhas+max_lin-1)/max_lin);
    }
    return 0;
}
