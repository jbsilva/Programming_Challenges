// ============================================================================
//
//       Filename:  01239-bloggo_shortcuts.cpp
//
//    Description:  URI 1239 - Bloggo Shortcuts
//
//        Version:  1.0
//        Created:  10/06/2012 01:10:55 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    bool abre = false;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '_')
            if ((abre = !abre))
                fputs("<i>", stdout);
            else
                fputs("</i>", stdout);
        else if (c == '*')
            if ((abre = !abre))
                fputs("<b>", stdout);
            else
                fputs("</b>", stdout);
        else
            putchar(c);
    }
    return 0;
}
