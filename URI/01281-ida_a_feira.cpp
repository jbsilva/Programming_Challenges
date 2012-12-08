// ============================================================================
// 
//       Filename:  01281-ida_a_feira.cpp
// 
//    Description:  URI 1281 - Ida à Feira
// 
//        Version:  1.0
//        Created:  08/Dec/2012 20:51:04
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <map>
#include <string>
using namespace std;


int main()
{
    int cases, qtd_prod, qtd_compra, qtd;
    double preco, soma;
    char nome[51];
    map<string, double> tabela; // tabela de preços

    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d ", &qtd_prod);
        while (qtd_prod--)
        {
            scanf("%s %lf", nome, &preco);
            tabela[string(nome)] = preco;
        }

        soma = 0.0;
        scanf("%d ", &qtd_compra);
        while (qtd_compra--)
        {
            scanf("%s %d", nome, &qtd);
            soma += qtd * tabela[string(nome)];
        }

        printf("R$ %.2lf\n", soma);
    }

    return 0;
}
