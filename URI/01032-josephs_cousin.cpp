// ============================================================================
//
//       Filename:  01032-josephs_cousin.cpp
//
//    Description:  URI 1032 - Joseph's Cousin
//
//        Version:  1.0
//        Created:  29/Jun/2013 20:24:54
//
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;


const int MAX = 35000;
const int TAM = (MAX - 1) / 2;
const int LIM = sqrt(MAX) / 2;


int main()
{
    // Crivo de Eratóstenes
    bool eh_composto[TAM];
    memset(eh_composto, 0, TAM * sizeof(bool));
    eh_composto[0] = 1;
    for (int i = 1; i <= LIM; i++)
        if (!eh_composto[i])
            for (int j = 2 * i * (i + 1); j < TAM; j += 2 * i + 1)
                eh_composto[j] = 1;

    // Cria vetor com todos os primos
    int primos[3550], qtd = 0;
    primos[qtd++] = 2;
    for (int i = 1; qtd <= 3510; i++)
        if (!eh_composto[i])
            primos[qtd++] = 2 * i + 1;

    // Josephus!
    vector<int> roda;
    int n;
    while (scanf("%d", &n) && n)
    {
        // Cria vetor com inteiros
        for (int i = 1; i <= n; i++)
            roda.push_back(i);

        int prox = 0, i = 0; // Próxima pessoa a sair
        while (n > 1)
        {
            prox = (prox - 1 + primos[i++]) % n;
            roda.erase(roda.begin() + prox);
            n--;
        }

        printf("%d\n", roda[0]);

        roda.clear();
    }

    return 0;
}
