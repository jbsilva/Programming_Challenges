// ===================================================================
//
//       Filename:  10229-modular_fibonacci.cpp
//
//    Description:  UVa 10229 - Modular Fibonacci
//                  O progrma deve imprimir fibonacci(n) % 2^m.
//                  A sequência se repete com o chamado período de Pisano, mas
//                  como não sei um método prático para achar esse período,
//                  usei bruteforce que utiliza um algorimo theta(log(n)) para
//                  calcular o fibonacci já com o módulo.
//
//        Version:  1.0
//        Created:  08/31/2012 03:57:31 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <iostream>
using namespace std;

typedef struct
{
    unsigned int m[2][2];
} M2x2;

int k;
// Multiplica matrizes 2x2: a*b = c. Depois tira mod k
M2x2 m_mul(M2x2 a, M2x2 b)
{
    M2x2 c;
    c.m[0][0] = ((a.m[0][0] * b.m[0][0]) % k + (a.m[0][1] * b.m[1][0]) % k) % k;
    c.m[0][1] = ((a.m[0][0] * b.m[0][1]) % k + (a.m[0][1] * b.m[1][1]) % k) % k;
    c.m[1][0] = ((a.m[1][0] * b.m[0][0]) % k + (a.m[1][1] * b.m[1][0]) % k) % k;
    c.m[1][1] = ((a.m[1][0] * b.m[0][1]) % k + (a.m[1][1] * b.m[1][1]) % k) % k;
    return c;
}

// Retorna a^n = b.
// Não precisa tratar n=0.
M2x2 m_exp(M2x2 a, int n)
{
    M2x2 b;
    if (n == 1)
        return a;
    else if (n % 2 == 0)
    {
        b = m_exp(a, n / 2);
        b = m_mul(b, b);
        return b;
    }
    else
    {
        b = m_exp(a, (n - 1) / 2);
        b = m_mul(b, b);
        return (m_mul(b, a));
    }
}


inline unsigned int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    M2x2 a;
    a.m[0][0] = 1; a.m[0][1] = 1;
    a.m[1][0] = 1; a.m[1][1] = 0;
    a = m_exp(a, n - 1);
    return a.m[0][0];
}
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        k = 1 << m;
        cout << fib(n) << endl;
    }
    return 0;
}
