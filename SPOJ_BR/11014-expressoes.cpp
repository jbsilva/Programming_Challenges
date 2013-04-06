// ============================================================================
//
//       Filename:  11014-expressoes.cpp
//
//    Description:  OBI 2011 - Fase 2, nível 2
//
//                  SPOJ BR 11014 - Expressões
//                  br.spoj.com/problems/EXPRES11/
//
//        Version:  1.0
//        Created:  06/Apr/2013 18:11:48
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;


int main()
{
    char lin[100001];
    int T;

    scanf("%d ", &T);
    while (T--)
    {
        stack<char> p;
        int tam = strlen(gets(lin));
        bool bem_definida = true;

        for (int i = 0; i < tam && bem_definida; i++)
        {
            switch (lin[i])
            {
                case '{': case '[': case '(':
                    p.push(lin[i]); break;
                case '}':
                    if (!p.empty() && p.top() == '{')
                        p.pop();
                    else
                        bem_definida = false;
                    break;
                case ']':
                    if (!p.empty() && p.top() == '[')
                        p.pop();
                    else
                        bem_definida = false;
                    break;
                case ')':
                    if (!p.empty() && p.top() == '(')
                        p.pop();
                    else
                        bem_definida = false;
                    break;
            }
        }

        if (!bem_definida || !p.empty())
            puts("N");
        else
            puts("S");
    }

    return 0;
}

