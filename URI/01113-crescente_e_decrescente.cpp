// ============================================================================
// 
//       Filename:  01113-crescente_e_decrescente.cpp
// 
//    Description:  URI 1113 - Crescente e Decrescente
// 
//        Version:  1.0
//        Created:  09/30/2012 02:00:30 PM
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
    int x, y;

    while (scanf("%d %d", &x, &y) != EOF && x != y)
        puts(x < y ? "Crescente" : "Decrescente");

    return 0;
}
