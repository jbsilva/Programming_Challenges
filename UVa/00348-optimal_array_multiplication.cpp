// ===================================================================
//
//       Filename:  00348.cpp
//
//    Description:  UVa 348 - Optimal Array Multiplication Sequence
//                  Implementação baseada no CLRS capítulo 15.2
//
//                  Complexidade: O(n^3).
//                  Existe um algoritmo n*log(n) para a mesma função.
//
//        Version:  1.0
//        Created:  09/08/2012 05:48:56 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <iostream>
using namespace std;

#define INF 1000000000                                  // Cuidado com overflow

int s[11][11]; // index k onde o # de múltiplos é min.: Ai..k * Ak+1..j = Ai..j

void parentisa(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        parentisa(i, s[i][j]);
        cout << " x ";
        parentisa(s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int p[14];
    int m[11][11];   // m[i][j] -> Minimo de múltiplicações para computar Ai..j
    int qtd_m, caso = 0;
    while (cin >> qtd_m && qtd_m)
    {
        // Dimensões da i-ésima matriz (começa da 1): p[i-1] x p[i]
        int i, col;
        for (i = 0; i < qtd_m; i++)
            cin >> p[i] >> col;
        p[i] = col;
        // Não precisa de múltiplicação nenhuma para calcular Ai..i = A[i]
        for (int i = 1; i <= qtd_m; i++)
            m[i][i] = 0;
        for (int len = 2; len <= qtd_m; len++) // len é o comprimento da cadeia
            for (int i = 1; i <= qtd_m - len + 1; i++)
            {
                int j = i + len - 1;
                m[i][j] = INF;
                for (int k = i; k < j; k++)
                {
                    // Testa custo de dividir cadeia em cada índice k
                    // p[i-1]*p[k]*p[j]: custo da multiplicação Ai..k * Ak+1..j
                    int custo = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (custo < m[i][j])
                    {
                        m[i][j] = custo;
                        s[i][j] = k;
                    }
                }
            }
        cout << "Case " << ++caso << ": ";
        parentisa(1, qtd_m);
        cout << endl;
    }
    return 0;
}
