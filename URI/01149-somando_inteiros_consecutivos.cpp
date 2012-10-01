// ============================================================================
// 
//       Filename:  01149-somando_inteiros_consecutivos.cpp
// 
//    Description:  URI 1149 - Somando Inteiros Consecutivos
// 
//        Version:  1.0
//        Created:  09/30/2012 05:01:26 PM
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
    int a, n, soma, ultimo;
    scanf("%d", &a);

    do
    {
        scanf("%d", &n);
    } while (n <= 0);


    ultimo = a + n - 1;

    if (n % 2)
        soma = (a+ultimo-1)*(n/2) + ultimo;
    else
        soma = (a+ultimo)*n/2;

    printf("%d\n", soma);

    return 0;
}
