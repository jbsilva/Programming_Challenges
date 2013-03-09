// ============================================================================
//
//       Filename:  1831-f91.cpp
//                  10696-f91.cpp
//
//    Description:  SPOJ-BR: br.spoj.pl/problems/F91/
//                  UVa: 10696
//
//        Version:  1.0
//        Created:  09/13/2012 06:01:59 PM
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
    unsigned int n;
    scanf("%u", &n);
    while (n)
    {
        printf("f91(%u) = %u\n", n, (n > 101) ? n - 10 : 91);
        scanf("%u", &n);
    }
    return 0;
}
