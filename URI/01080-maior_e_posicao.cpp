// ============================================================================
// 
//       Filename:  01080-maior_e_posicao.cpp
// 
//    Description:  URI 1080 - Maior e Posição
// 
//        Version:  1.0
//        Created:  09/30/2012 12:10:05 AM
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
    int n, maior=0, index=0;
    for (int i=1; i <= 100; i++)
    {
        scanf("%d", &n);
        if (n > maior)
        {
            maior = n;
            index = i;
        }
    }

    printf("%d\n%d\n", maior, index);

    return 0;
}
