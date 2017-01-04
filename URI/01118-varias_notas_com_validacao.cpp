// ============================================================================
//
//       Filename:  01118-varias_notas_com_validacao.cpp
//
//    Description:  URI 1118 - Várias notas com Validação
//
//        Version:  1.0
//        Created:  09/30/2012 02:38:26 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    char repetir = '1'; // Repetir? 1-sim, 2-nao
    double n1, n2;
    while (repetir == '1')
    {
        while (scanf("%lf ", &n1) != EOF && (n1 < 0 || n1 > 10))
            puts("nota invalida");
        while (scanf("%lf ", &n2) != EOF && (n2 < 0 || n2 > 10))
            puts("nota invalida");
        printf("media = %.2lf\n", (n1 + n2) / 2);
        do
        {
            puts("novo calculo (1-sim 2-nao)");
            scanf("%c ", &repetir);
        }
        while (repetir != '1' && repetir != '2');
    }
    return 0;
}
