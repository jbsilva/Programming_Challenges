// ===================================================================
//
//       Filename:  00374-big_mod.cpp
//
//    Description:  UVa 374 - Big Mod
//
//        Version:  1.0
//        Created:  08/31/2012 03:33:06 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <iostream>
using namespace std;

typedef long long int LLI;


LLI bigmod(LLI b, LLI p, LLI m)
{
    if (p == 0)
        return 1;
    // Expoentes pares
    if (p % 2 == 0)
    {
        LLI temp = bigmod(b, p / 2, m);
        return (temp * temp) % m;
    }
    // Expoentes ímpares
    return ((b % m) * bigmod(b, p - 1, m)) % m;
}


int main()
{
    LLI b, p, m;
    while (cin >> b >> p >> m)
        cout << bigmod(b, p, m) << endl;
    return 0;
}
