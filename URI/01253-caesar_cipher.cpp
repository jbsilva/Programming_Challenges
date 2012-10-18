// ============================================================================
// 
//       Filename:  01253-caesar_cipher.cpp
// 
//    Description:  URI 1253 - Caesar Cipher
// 
//        Version:  1.0
//        Created:  18/Oct/2012 10:29:44
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    int cases, shift;
    char str[52];

    scanf("%d", &cases);
    while (cases--)
    {
        getchar(); // '\n'
        gets(str);
        int tam = strlen(str);

        scanf("%d", &shift);

        for (int i=0; i < tam; i++)
        {
            if (str[i] - shift >= 'A')
                putchar(str[i] - shift);
            else
                putchar('Z' - ('A' - (str[i]-shift)) + 1);
        }
        putchar('\n');
    }

    return 0;
}
