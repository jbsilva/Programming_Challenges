// ============================================================================
//
//       Filename:  11608-estacionamento.cpp (SPOJ BR)
//                  01246-estacionamento.cpp (URI)
//
//    Description:  SPOJ BR 11608 - Estacionamento
//                  URI 1246 - Estacionamento
//                  Primeira fase da Maratona de Programação - 2011
//                  http://br.spoj.pl/problems/ESTAC/
//
//        Version:  1.0
//        Created:  11/Oct/2012 17:25:58
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <map>
using namespace std;

typedef struct
{
    int ini; // posição inicial
    int tam; // tamanho da vaga em metros
} vaga;

int main()
{
    map<int, vaga> car; // Posições ocupadas pelos carros. Chaves são as placas
    int free_from[1001];       // metros vazios a partir de determinada posição
    int comp, eventos, tam, faturamento, placa, ini, fim, i, j;
    char in_out;
    while (scanf("%d %d ", &comp, &eventos) != EOF)
    {
        for (i = 0, j = comp; i < comp; i++, j--)
            free_from[i] = j;
        free_from[comp] = 0; // margem
        faturamento = 0;
        while (eventos--)
        {
            in_out = getchar();
            if (in_out == 'C')
            {
                scanf("%d %d ", &placa, &tam);
                for (i = 0; i < comp; i++)
                    if (free_from[i] >= tam)
                    {
                        car[placa].ini = i;
                        car[placa].tam = tam;
                        for (j = 0; j < tam; j++)
                            free_from[i + j] = 0;
                        faturamento += 10;
                        break;
                    }
            }
            else
            {
                scanf("%d ", &placa);
                tam = car[placa].tam;                // tamanho do carro saindo
                ini = car[placa].ini;                // posição inicial
                fim = ini + tam - 1;                 // posição final
                // vagas livres à direita. Por isso coloquei aquela margem
                int v = free_from[fim + 1];
                // Preenche posições onde estava o carro
                for (i = fim; i >= ini; i--)
                    free_from[i] = ++v;
                // Preenche posições à esquerda de onde estava o carro
                for (i = ini - 1; i >= 0 && free_from[i]; i--)
                    free_from[i] = ++v;
            }
        }
        printf("%d\n", faturamento);
        car.clear();
    }
    return 0;
}
