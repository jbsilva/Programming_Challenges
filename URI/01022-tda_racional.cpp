// ============================================================================
//
//       Filename:  01022-tda_racional.cpp
//
//    Description:  URI 1022 - TDA Racional
//
//        Version:  1.0
//        Created:  08/Oct/2012 18:40:25
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>
using namespace std;

// MDC
int gcd(int a, int b)
{
    while (b > 0)
    {
        a = a % b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int main()
{
    int cases, a, b, c, d, num1, num2, den1, den2, mdc;
    char op;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d / %d %c %d / %d", &a, &b, &op, &c, &d);
        switch (op)
        {
            case '+':
                num1 = a * d + c * b;
                den1 = b * d;
                break;
            case '-':
                num1 = a * d - c * b;
                den1 = b * d;
                break;
            case '*':
                num1 = a * c;
                den1 = b * d;
                break;
            case '/':
                num1 = a * d;
                den1 = b * c;
        }
        mdc = gcd(abs(num1), abs(den1));
        num2 = num1 / mdc;
        den2 = den1 / mdc;
        printf("%d/%d = %d/%d\n", num1, den1, num2, den2);
    }
    return 0;
}
