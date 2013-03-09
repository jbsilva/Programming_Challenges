// ===================================================================
//
//       Filename:  10090-marbles.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  09/20/2012 05:50:10 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <iostream>
#include <cmath>
using namespace std;

#define DEBUG 0

typedef long long LLI;

LLI mdc_ext(LLI a, LLI b, LLI& x, LLI& y)
{
    LLI q, r, x1, x2, y1, y2;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 0)
    {
        x = 1; y = 0;
        return a;
    }
    x2 = 1; x1 = 0;
    y2 = 0; y1 = 1;
    while (b > 0)
    {
        q = a / b;        r = a - q * b;
        x = x2 - q * x1;  y = y2 - q * y1;
        a = b;          b = r;
        x2 = x1;        x1 = x;
        y2 = y1;        y1 = y;
    }
    x = x2; y = y2;
    return a;
}


int main()
{
    LLI m; // qtd total de marbles
    while (cin >> m && m)
    {
        LLI c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;
        LLI _b1, _b2; // Solucão genérica da eq. diofantina
        LLI gcd = mdc_ext(n1, n2, _b1, _b2);
        if (m % gcd != 0)
            cout << "failed" << endl;
        else
        {
            _b1 *= m / gcd;
            _b2 *= m / gcd;
            LLI k1 = ceil((double)(-_b1 * gcd) / n2);
            LLI k2 = floor((double)(_b2 * gcd) / n1);
            // Não existe solução positiva
            if (k2 < k1)
                cout << "failed" << endl;
            else
            {
                LLI custo1 = c1 * _b1 + c2 * _b2 + k1 * (c1 * n2 - c2 * n1) / gcd;
                LLI custo2 = c1 * _b1 + c2 * _b2 + k2 * (c1 * n2 - c2 * n1) / gcd;
                LLI k = custo1 < custo2 ? k1 : k2;
                LLI b1 = _b1 + n2 / gcd * k;
                LLI b2 = _b2 - n1 / gcd * k;
#if DEBUG
                cout << "gcd: " << gcd << endl;
                cout << "_b1: " << _b1 << endl;
                cout << "_b2: " << _b2 << endl;
                cout << "b1: " << b1 << endl;
                cout << "b2: " << b2 << endl;
                cout << "k1: " << k1 << endl;
                cout << "k2: " << k2 << endl;
                cout << "custo1: " << custo1 << endl;
                cout << "custo2: " << custo2 << endl;
#endif
                cout << b1 << " " << b2 << endl;
            }
        }
    }
    return 0;
}
