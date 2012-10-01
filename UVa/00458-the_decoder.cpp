// ============================================================================
// 
//       Filename:  00458-the_decoder.cpp
// 
//    Description:  UVa 458 - The Decoder
// 
//        Version:  1.0
//        Created:  10/01/2012 08:03:05 PM
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
    char c;

    while ((c=getchar()) != EOF)
    {
        if (c == '\n')
            putchar('\n');
        else
            putchar(c-7);
    }

    return 0;
}
