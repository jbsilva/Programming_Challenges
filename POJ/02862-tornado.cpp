// ============================================================================
//
//       Filename:  02862-tornado.cpp (POJ)
//                  01266-tornado.cpp (URI)
//
//    Description:  ACM/ICPC South America Contest 2005
//                  POJ 2862 - Tornado!
//                  URI 1266 - Tornado!
//
//        Version:  2.0
//        Created:  09/Aug/2012 12:19:58 -> Competição do grupo do Facebook: WA
//                  04/Feb/2013 19:35:41 -> 2a tentativa: AC
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
    int qtd_postes, i, repor, atual, primeiro, segundo, anterior;
    while (scanf("%d", &qtd_postes) && qtd_postes)
    {
        repor = 0;      // Saída
        atual = primeiro = anterior = 1;
        for (i = 0; i < qtd_postes; i++)
        {
            scanf("%d", &atual);
            // guarda 1o poste
            if (i == 0)
                primeiro = atual;
            else if (i == 1)
                segundo = atual;
            // Se o 1o e o 2o postes foram destruídos, mas não o 3o, então é
            // melhor repor o primeiro poste e não o segundo.
            else if (i == 2 && segundo == 0 && atual == 1)
                primeiro = 1;
            if (anterior == 0 && atual == 0)
            {
                repor++;
                atual = 1; // Repõe o poste atual.
            }
            // Último poste. A fazenda é circular
            if (i == qtd_postes - 1 && primeiro == 0 && atual == 0)
                repor++;
            anterior = atual;
        }
        printf("%d\n", repor);
    }
    return 0;
}

