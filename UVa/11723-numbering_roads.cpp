// ============================================================================
//
//       Filename:  11723-numbering_roads.cpp (UVa)
//                  01306-numbering_roads.cpp (URI)
//
//    Description:  UVa 11723 - Numbering Roads
//                  URI 1306 - Numbering Roads
//
//        Version:  1.0
//        Created:  05/Mar/2013 12:31:14
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

int main()
{
    int R, N, d, caso = 0;
    while (scanf("%d %d", &R, &N) && (R || N))
    {
        printf("Case %d: ", ++caso);
        d = (R + N - 1) / N - 1; // d = ceil(R/N) - 1
        if (d > 26)
            puts("impossible");
        else if (d <= 0)
            puts("0");
        else
            printf("%d\n", d);
    }
    return 0;
}

