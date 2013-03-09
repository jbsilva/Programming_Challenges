// ============================================================================
//
//       Filename:  01171-frequencia_de_numeros.cpp
//
//    Description:  URI 1171 - Frequência de Números
//
//        Version:  1.0
//        Created:  13/Oct/2012 03:11:40
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    int qtd, n;
    int num[2001];
    memset(num, 0, sizeof(num));
    scanf("%d", &qtd);
    while (qtd--)
    {
        scanf("%d", &n);
        num[n]++;
    }
    for (int i = 0; i <= 2000; i++)
        if (num[i])
            printf("%d aparece %d vez(es)\n", i, num[i]);
    return 0;
}
