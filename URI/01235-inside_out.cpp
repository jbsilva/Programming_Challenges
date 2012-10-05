// ============================================================================
// 
//       Filename:  01235-inside_out.cpp
// 
//    Description:  URI 01235 - Inside Out
// 
//        Version:  1.0
//        Created:  10/05/2012 02:13:14 AM
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
    char str[102];

    int cases;
    scanf("%d", &cases);
    getchar(); // \n

    while (cases--)
    {
        gets(str);
        int tam = strlen(str);

        for (int i=tam/2-1; i >= 0; i--)
            putchar(str[i]);
        for (int i=tam-1; i >= tam/2; i--)
            putchar(str[i]);
        putchar('\n');
    }

    return 0;
}
