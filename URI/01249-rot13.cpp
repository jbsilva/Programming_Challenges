// ============================================================================
// 
//       Filename:  01249-rot13.cpp
// 
//    Description:  URI 1249 - Rot13
// 
//        Version:  1.0
//        Created:  11/Oct/2012 16:28:34
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
    char rot_min[]={'n','o','p','q','r','s','t','u','v','w','x','y','z',
        'a','b','c','d','e','f','g','h','i','j','k','l','m'};
    char rot_mai[]={'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M'};

    char c;
    while ( (c=getchar()) != EOF )
    {
        if (c >= 'a' && c <= 'z')
            putchar(rot_min[c-'a']);
        else if (c >= 'A' && c <= 'Z')
            putchar(rot_mai[c-'A']);
        else
            putchar(c);
    }

    return 0;
}
