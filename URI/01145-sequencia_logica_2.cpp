// ============================================================================
// 
//       Filename:  01145-sequencia_logica_2.cpp
// 
//    Description:  URI 1145 - Sequência Lógica 2
// 
//        Version:  1.0
//        Created:  09/30/2012 04:31:29 PM
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
    scanf("%d %d", &x, &y);

    for (int i=1; i <= y; i++)
        if (i % x != 0)
            printf("%d ", i);
        else
            printf("%d\n", i);

    return 0;
}
