// ============================================================================
//
//       Filename:  00272-tex_quotes.cpp
//
//    Description:  UVa 272 - TEX Quotes
//
//        Version:  1.0
//        Created:  10/01/2012 08:15:03 PM
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
    bool abre = false;
    char c;
    while ((c = getchar()) != EOF)
        if (c == '"')
            if ((abre = !abre))
                fputs("``", stdout);
            else
                fputs("''", stdout);
        else
            putchar(c);
    return 0;
}
