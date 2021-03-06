// ============================================================================
//
//       Filename:  01241-encaixa_ou_nao_i.cpp
//
//    Description:  URI 1241 - Encaixa ou Não II
//                  Mesmo código do problema 1240 com arrays maiores
//
//        Version:  1.0
//        Created:  07/Oct/2012 16:03:29
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    int qtd, tam_a, tam_b;
    char a[1002], b[1002];
    scanf("%d", &qtd);
    getchar(); // '\n'
    while (qtd--)
    {
        scanf("%s %s", a, b);
        tam_a = strlen(a);
        tam_b = strlen(b);
        bool encaixa = true;
        if (tam_a >= tam_b)
        {
            for (int i = 1; i <= tam_b; i++)
                if (a[tam_a - i] != b[tam_b - i])
                {
                    encaixa = false;
                    break;
                }
        }
        else
            encaixa = false;
        if (encaixa)
            puts("encaixa");
        else
            puts("nao encaixa");
    }
    return 0;
}
