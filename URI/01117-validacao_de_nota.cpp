// ============================================================================
// 
//       Filename:  01117-validacao_de_nota.cpp
// 
//    Description:  URI 1117 - Validação de Nota
// 
//        Version:  1.0
//        Created:  09/30/2012 02:29:06 PM
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
    double n1, n2;

    while (scanf("%lf", &n1) != EOF && (n1 < 0 || n1 > 10))
        puts("nota invalida");

    while (scanf("%lf", &n2) != EOF && (n2 < 0 || n2 > 10))
        puts("nota invalida");

    printf("media = %.2lf\n", (n1+n2)/2);

    return 0;
}
