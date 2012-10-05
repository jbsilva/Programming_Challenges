// ============================================================================
// 
//       Filename:  01216-getline_one.cpp
// 
//    Description:  URI 1216 - Getline One
// 
//        Version:  1.0
//        Created:  10/05/2012 05:09:45 PM
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
    char nome[300];
    int dist, soma = 0, qtd = 0;
    while (gets(nome))
    {
        scanf("%d", &dist);
        soma += dist;
        qtd++;
    }

    printf("%.1lf\n", (double)soma/qtd);

    return 0;
}
