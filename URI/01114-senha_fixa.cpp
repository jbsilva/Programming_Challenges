// ============================================================================
//
//       Filename:  01114-senha_fixa.cpp
//
//    Description:  URI 1114 - Senha Fixa
//
//        Version:  1.0
//        Created:  09/30/2012 02:10:44 PM
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
    int sen;
    scanf("%d", &sen);
    while (sen != 2002)
    {
        puts("Senha Invalida");
        scanf("%d", &sen);
    }
    puts("Acesso Permitido");
    return 0;
}
