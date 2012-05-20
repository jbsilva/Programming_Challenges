// =====================================================================================
// 
//       Filename:  10198-counting.cpp
// 
//    Description:  UVA 10198
//
//                  Seja f(n) o número de combinações cuja soma é n.
//                  f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-1)
// 
//        Version:  1.0
//        Created:  04/19/2011 06:02:57 AM
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

const int MAX_COMB = 1001;

int main()
{
    USI n, i;
    BigNum comb[MAX_COMB];

    // gera vetor de BigNum com todas as o número de combinações possíveis até n=MAX_COMB
    comb[1] = 2;
    comb[2] = 5;
    comb[3] = 13;
    
    for (i=4; i<MAX_COMB; i++)
        comb[i] = comb[i-1] + comb[i-1] + comb[i-2] + comb[i-3];

    while (cin >> n)
        cout << comb[n] << endl;

    return 0;
}
