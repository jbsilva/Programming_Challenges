// ============================================================================
//
//       Filename:  01177-preenchimento_de_vetor_ii.cpp
//
//    Description:  URI 1177 - Preenchimento de Vetor II
//
//        Version:  1.1
//        Created:  09/28/2012 03:38:35 PM
//       Revision:  Troquei iostream por cstdio para conseguir 0.00s
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < 1000; i++)
        printf("N[%d] = %d\n", i, i % t);
    return 0;
}
