// ============================================================================
// 
//       Filename:  01077-infixa_para_posfixa.cpp
// 
//    Description:  URI 1077 - Infixa para Posfixa
//                  Minha implementação do Shunting-yard algorithm
// 
//        Version:  1.0
//        Created:  10/05/2012 07:00:59 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

#define is_op(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')

inline int preced(const char c)
{
    switch(c)
    {
        case '^': return 3;
        case '*':  case '/': return 2;
        case '+': case '-': return 1;
    }
    return 0;
}
 

inline bool is_left(const char c)
{
    switch(c)
    {
        case '*': case '/': case '+': case '-': return true;
        case '^': return false;
    }
    return false;
}


int main()
{
    stack<char> pilha;
    char c;
    int cases;
    
    scanf("%d ", &cases);
    while (cases--)
    {
        while ((c = getchar()) != '\n')
        {
            if (isalnum(c))
                putchar(c);
            else if (is_op(c))
            {
                while (!pilha.empty() && is_op(pilha.top()) &&
                        ( (is_left(c) && preced(c) <= preced(pilha.top())) ||
                          (preced(c) < preced(pilha.top())) ))
                {
                    putchar(pilha.top());
                    pilha.pop();
                }
                pilha.push(c);
            }
            else if (c == '(')
                pilha.push(c);
            else if (c == ')')
            {
                while (pilha.top() != '(')
                {
                    putchar(pilha.top());
                    pilha.pop();
                }
                pilha.pop(); // remove '(' da pilha
            }
        }

        while (!pilha.empty())
        {
            putchar(pilha.top());
            pilha.pop();
        }
        putchar('\n');
    }

    return 0;
}
