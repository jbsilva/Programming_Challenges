// =====================================================================================
// 
//       Filename:  10157-expressions.cpp
// 
//    Description:  UVA 10157
//
//                  Uma expressão corretamente construida é da forma
//                      B = (X)Y
//                  com comprimento n e profundidade d.
//                  
//                  Chamamos k o comprimento da parte (X). Então:
//                      Comprimento de X: (k-2)
//                      Comprimento de Y: (n-k)
//
//                  Como os comprimentos devem ser não negativos,
//                      2 <= k <= n
//
//                  Cada parênteses deve ter um correspondente contrário. Então
//                      k deve ser par
//
//                  Como 'B' tem profundidade d, então a profundidade de (X) e de Y <= d
//                  e profundidade de X <= d-1
//
//                  Então as possibilidades são:
//                      f(k-2,d-1) para X
//                      f(n-k,d) para Y
//
//                  Pela regra da contagem, existem f(k-2,d-1)*f(n-k,d) possibilidades para B,
//                  para determinado k.
//                  O total de combinações para B é o somatório de f(k-2, d-1)*f(n-k,d) para todo k
//
//                          n
//                          ___
//                 f(n,d) = \   f(k-2,d-1) * f(n-k,d)
//                          /__
//                          k=2
//                        k é par
// 
//                  A função f(n,d) resulta em um número de combinações de profundidade 0...d
//                  Para achar o número de combinações de profundidade d:
//                      f(n,d) - f(n,d-1)
//
//                  Mais info: http://online-judge.uva.es/board/viewtopic.php?f=10&t=908
//
//                  ----------------
//
//                  Aloquei memória dinamicamente, pois a stack não suporta os 45451 BigNum,
//                  que ocupam por volta de 23MB
//
//                  O algoritmo está correto. O desempenho depende da implementação do BigNum
//
//        Version:  1.0
//        Created:  04/18/2011 11:30:34 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include "../BigNum.h"
using namespace std;

typedef unsigned short int USI;
typedef long long int LLI;

const USI MAX_LENGTH = 301;
const USI MAX_DEPTH = 151;

int main()
{
    BigNum **maneiras;
    
    USI n, d, k;

    // Aloca memória na heap
    maneiras = new BigNum*[MAX_LENGTH];

    for (int i=0; i<MAX_LENGTH; i++)
        maneiras[i] = new BigNum[MAX_DEPTH];

    // Gera todos os números e armazena em um vetor de BigNum

    // Caso base
    for (d=0; d<MAX_DEPTH; d++)
        maneiras[0][d] = (LLI)1;

    // Para n par. (não precisa para n ímpar, pois o BigNum já os inicia em 0)
    for(n=2; n<MAX_LENGTH; n+=2)
        for (d=1; d<MAX_DEPTH; d++)
            for(k=2; k<=n; k+=2)
                maneiras[n][d] += maneiras[k-2][d-1] * maneiras[n-k][d];
    
    while( cin >> n >> d)
        cout << maneiras[n][d] - maneiras[n][d-1] << endl;

    delete[] maneiras;
    
    return 0;
}
