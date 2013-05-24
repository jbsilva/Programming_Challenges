// ============================================================================
//
//       Filename:  01063-trilhos_novamente_tracando_movimentos.cpp
//
//    Description:  URI 1063 - Trilhos Novamente… Traçando Movimentos
//
//                  Este problema faz referência ao URI 1062.
//
//        Version:  1.0
//        Created:  23/May/2013 21:21:54
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <stack>
using namespace std;


int main()
{
    int v, ia, ib;
    char A[30], B[30];
    stack<char> S;
    while (scanf("%d ", &v) && v)
    {
        for (int i = 0; i < v; i++) scanf("%c ", &A[i]); A[v] = '\0';
        for (int i = 0; i < v; i++) scanf("%c ", &B[i]); B[v] = '\0';
        ia = ib = 0;
        while (ia < v)
        {
            S.push(A[ia++]); putchar('I');
            while (!S.empty() && S.top() == B[ib])
            {
                S.pop(); putchar('R');
                ib++;
            }
        }
        if (!S.empty()) printf(" Impossible");
        putchar('\n');
        S = stack<char>(); // clear
    }
    return 0;
}

