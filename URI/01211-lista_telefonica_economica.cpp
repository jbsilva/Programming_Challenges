// ============================================================================
//
//       Filename:  01211-lista_telefonica_economica.cpp
//
//    Description:  URI 1211 - Lista telefônica econômica
//
//        Version:  1.1
//        Created:  10/05/2012 12:35:34 PM
//       Revision:  10/05/2012 16:30:00 PM
//                      Troquei vector de string por array de char[] para
//                      ficar mais rápido.
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>


inline int comp_str(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b);
}


int main()
{
    char lista[100001][21];
    int qtd, cps; // qtd = quantidade de telefones; cps = common prefix size
    while (scanf("%d ", &qtd) != EOF)
    {
        for (int i = 0; i < qtd; i++)
            gets(lista[i]);
        qsort(lista, qtd, 21 * sizeof(char), comp_str);
        cps = 0;
        for (int i = 1; i < qtd; i++)
            for (int j = 0; j < 20; j++)        // Sempre sai antes do 20 mesmo
                if (lista[i - 1][j] != lista[i][j])
                    break;
                else
                    cps++;
        printf("%d\n", cps);
    }
    return 0;
}
