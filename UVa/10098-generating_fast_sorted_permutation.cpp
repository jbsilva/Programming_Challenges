// ============================================================================
//
//       Filename:  10098-generating_fast_sorted_permutation.cpp (UVa)
//                  01401-generating_fast_sorted_permutation.cpp (URI)
//
//    Description:  UVa 10098 - Generating Fast, Sorted Permutation
//                  URI 1401 - Generating Fast, Sorted Permutation
//
//                  Semelhante ao "Rosalind - perm", mas a saída deve ser
//                  ordenada. Por sorte, a STL já possui uma função para isso.
//
//        Version:  1.0
//        Created:  17/May/2013 23:04:31
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
    char str[11];
    int n, len;
    scanf("%d ", &n);
    while (n--)
    {
        len = strlen(gets(str));
        sort(str, str + len);
        do
        {
            puts(str);
        }
        while (next_permutation(str, str + len));
        putchar('\n');
    }
    return 0;
}

