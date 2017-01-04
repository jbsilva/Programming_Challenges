// ============================================================================
//
//       Filename:  01151-fibonacci_facil.cpp
//
//    Description:  URI 1151 - Fibonacci Fácil
//
//        Version:  1.0
//        Created:  09/30/2012 08:14:32 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int f[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610,
               987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025,
               121393, 196418, 317811, 514229, 832040, 1346269, 2178309,
               3524578, 5702887, 9227465, 14930352, 24157817, 39088169,
               63245986, 102334155, 165580141, 267914296, 433494437, 701408733,
               1134903170, 1836311903};
    int n;
    scanf("%d", &n);
    putchar('0');
    for (int i = 1; i < n; i++)
        printf(" %d", f[i]);
    putchar('\n');
    return 0;
}
