// =====================================================================================
// 
//       Filename:  00861-little_bishops.cpp
// 
//    Description:  UVA 861
//                  Esse problema poderia ser resolvido por backtracking, mas essa não é
//                  a forma mais eficiente.
//
//                  Se um bispo iniciou o jogo em uma casa de determinada cor, ele apenas
//                  poderá atacar peças em casas dessa mesma cor, então podemos dividir
//                  o tabuleiro em casas brancas e pretas.
//                  
//                  Depois giramos 45 graus cada um desses tabureiros, de forma que os
//                  bispos agora se movimentem como torres (na vertical e horizontal).
//
//                  O vetor "linB" indica o número de casas em cada linha do novo
//                  tabuleiro girado, formado apenas por casas brancas.
//                      Exemplo, para um tabuleiro 6x6:
//                             *                  *         1
//                            ***                 *         1
//                           *****       =       ***        3
//                           *****               ***        3
//                            ***               *****       5
//                             *                *****       5
//
//                      Perceba que ambas as formas são equivalentes, já que a altura e a
//                      largura são iguais.
//
//                  O vetor "linP" incica o número de casas em cada linha do segundo
//                  tabuleiro girado, formado apenas por casas pretas.
//                      Exemplo, para um tabuleiro 6x6:
//                            **                 **          2
//                           ****                **          2
//                          ******      =       ****         4
//                           ****               ****         4
//                            **               ******        6
//
//                      Repare que existe uma linha a menos de casas pretas
//
//                  Observações:
//                      Para n=0, k também deve ser 0. O programa acaba
//                      Para k=0 existe uma possibilidade: deixar o tabuleiro vazio.
//                      Se k>2*n não existem possibilidades
//                      Para n=1 (e k=1), só existe uma possibilidade: Um bispo na única casa
//
//        Version:  1.0
//        Created:  05/11/2011 02:07:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
using namespace std;

typedef long long int LLI;

// Gera todas as possibilidades
LLI comb(int n, int k)
{
    int i, j;
    LLI linB[9], linP[9], cb[9][65], cp[9][65], arr;

    for (i=0; i<9; i++)
        for (j=0; j<65; j++)
            cb[i][j] = cp[i][j] = 0;

    // Qtd de casas brancas em cada linha do tabuleiro girado
    for (i=1; i<=n; i+=2)
        linB[i] = i;
    for (i=2; i<=n; i+=2)
        linB[i] = i-1;

    // Qtd de casas pretas em cada linha do tabuleiro girado
    for (i=1; i<=n-1; i+=2)
        linP[i] = i+1;
    for (i=2; i<=n; i+=2)
        linP[i] = i;

    // cb[i][j] representa as formas de colocar j torres em i linhas
    // k=0 retorna 1
    for (i=0; i<=n; i++)
        cb[i][0] = 1;

    // n=0 retorna 0
    for (i=1; i<=k; i++)
        cb[0][i] = 0;

    for (i=1; i<=n; i++)
        for (j=1; j<=k && j<=i; j++)
            cb[i][j] = cb[i-1][j] + cb[i-1][j-1]*(1 + linB[i] - j);

    // Casas pretas
    // k=0 retorna 1
    for (i=0; i<=n-1; i++)
        cp[i][0] = 1;

    // n=0 retorna 0
    for (i=1; i<=k; i++)
        cp[0][i] = 0;

    for (i=1; i<=n-1; i++)
        for (j=1; j<=k && j<=i; j++)
            cp[i][j] = cp[i-1][j] + cp[i-1][j-1]*(1 + linP[i] - j);

    // Calcula todos os arranjos possíveis
    arr = 0;
    for (i=0; i<=k; i++)
        arr += cb[n][i] * cp[n-1][k-i];

    return arr;
}

int main()
{
    int n, k;

    while ( cin >> n >> k && (n != 0 || k != 0) )
        cout << comb(n,k) << endl;

    return 0;
}
