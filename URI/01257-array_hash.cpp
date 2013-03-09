// ============================================================================
//
//       Filename:  01257-array_hash.cpp
//
//    Description:  URI 1257 - Array Hash
//
//        Version:  1.0
//        Created:  26/Oct/2012 15:12:46
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
    int cases, lines, tam;
    char str[51];
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &lines);
        getchar();
        int sum = 0;
        for (int lin = 0; lin < lines; lin++)
        {
            gets(str);
            tam = strlen(str);
            sum += tam * lin;
            for (int i = 0; i < tam; i++)
                sum += str[i] - 'A' + i;
        }
        printf("%d\n", sum);
    }
    return 0;
}
