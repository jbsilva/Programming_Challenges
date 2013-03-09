// ============================================================================
//
//       Filename:  01134-tipo_de_combustivel.cpp
//
//    Description:  URI 1134 - Tipo de Combustível
//
//        Version:  1.0
//        Created:  09/30/2012 03:26:32 PM
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
    int alcool = 0, gasolina = 0, diesel = 0;
    char ch = '0';
    while (ch != '4')
    {
        scanf("%c ", &ch);
        switch (ch)
        {
            case '1': alcool++; break;
            case '2': gasolina++; break;
            case '3': diesel++; break;
        }
    }
    puts("MUITO OBRIGADO");
    printf("Alcool: %d\nGasolina: %d\nDiesel: %d\n", alcool, gasolina, diesel);
    return 0;
}
