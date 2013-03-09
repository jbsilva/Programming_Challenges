// ============================================================================
//
//       Filename:  01192-o_jogo_matematico_de_paula.cpp
//
//    Description:  URI 1192 - O jogo Matemático de Paula
//
//        Version:  1.0
//        Created:  03/Nov/2012 22:01:40
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
    int cases, a, b;
    char c;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d%c%d", &a, &c, &b);
        if (a == b)
            printf("%d\n", a * a);
        else if (c >= 'A' && c <= 'Z')
            printf("%d\n", b - a);
        else
            printf("%d\n", a + b);
    }
    return 0;
}
