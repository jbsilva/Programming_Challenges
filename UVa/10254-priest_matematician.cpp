// =====================================================================================
// 
//       Filename:  10254-priest_matematician.cpp
// 
//    Description:  UVA 10254
//
//                  A fórmula de recorrência para esse problema é
//                      f(n) = 2 * f(n-k) + 2^k - 1
//                      f(0) = 0; f(1) = 1
//
//                  Recebi ajuda na dedução das fórmulas.
// 
//        Version:  1.0
//        Created:  04/22/2011 04:27:56 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <new>
#include <cstdlib>
#include "../BigNum.h"
using namespace std;

typedef long long int LLI;
typedef unsigned short int USI;

int main()
{
    BigNum *transf;
    BigNum *potencias;
    BigNum *diff;
    USI n, i;

    // Aloca memória na heap, pq a stack não aguenta
    transf = new BigNum[10001];
    potencias = new BigNum[1500];
    diff = new BigNum[10001];

    potencias[0] = 1;
    for (i=1; i<150; i++)
        potencias[i] = potencias[i-1] * 2;
    
    transf[0] = (LLI)0;
    transf[1] = (LLI)1;
    diff[0] = (LLI)0;
    diff[1] = (LLI)1;

    int k = 1;
    for (i=2; i<10001; i++)
    {
        if (diff[i-k] > potencias[k-1])
            k++;

        transf[i] = transf[i-k]*2;
        transf[i] += potencias[k];
        transf[i] -= 1;

        diff[i] = transf[i] - transf[i-1];
    }

    while (cin >> n)
        cout << transf[n] << endl;

    delete[] transf;
    delete[] potencias;
    delete[] diff;

    return 0;
}
