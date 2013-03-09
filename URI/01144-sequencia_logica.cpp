// ============================================================================
//
//       Filename:  01144-sequencia_logica.cpp
//
//    Description:  URI 1144 - Sequência Lógica
//
//        Version:  1.0
//        Created:  09/30/2012 04:24:42 PM
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
    int n;
    scanf("%d", &n);
    int i = 1;
    while (n--)
    {
        printf("%d %d %d\n", i, i * i, i * i * i);
        printf("%d %d %d\n", i, i * i + 1, i * i * i + 1);
        i++;
    }
    return 0;
}
