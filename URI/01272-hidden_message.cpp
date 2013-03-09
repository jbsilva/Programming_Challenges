// ============================================================================
//
//       Filename:  01272-hidden_message.cpp
//
//    Description:  URI 1272 - Hidden Message
//
//        Version:  1.0
//        Created:  03/Dec/2012 11:45:21
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    char str[51];
    int n;
    scanf("%d ", &n);
    while (n--)
    {
        gets(str);
        char* l = str, s[51];
        int offset;
        // O '%n' do sscanf retorna o número de caracteres consumidos.
        while (sscanf(l, "%s%n", s, &offset) != EOF)
        {
            l += offset; // incrementa ponteiro
            putchar(s[0]);
        }
        putchar('\n');
    }
    return 0;
}
