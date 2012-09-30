// ============================================================================
// 
//       Filename:  01101-sequencia_de_numeros_e_soma.cpp
// 
//    Description:  URI 1101 - Sequencia de Números/Valores e Soma
// 
//        Version:  1.0
//        Created:  09/30/2012 02:14:20 AM
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
    int m, n, maior, menor, sum;
    while (scanf("%d %d", &m, &n) != EOF && m > 0 && n > 0)
    {
        if (m > n) {maior = m; menor = n;}
        else {maior = n; menor = m;}

        sum = 0;
        for (int i=menor; i<=maior; i++)
        {
            sum += i;
            printf("%d ", i);
        }

        printf("Sum=%d\n", sum);
    }

    return 0;
}
