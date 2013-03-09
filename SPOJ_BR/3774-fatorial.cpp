// ============================================================================
//
//       Filename:  3774-fatorial.cpp
//
//    Description:  SPOJ BR 3774 - Fatorial
//                  Treino para OBI de 2006
//
//        Version:  1.0
//        Created:  08/Dec/2012 21:16:57
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
    /* Gerado usando:
     * fputs("\"1\"", stdout);
     * for (int soma=1, n=1; n < 13; soma*=++n) printf(", \"%d\"", soma);*/
    char f[][10] = {"1", "1", "2", "6", "24", "120", "720", "5040", "40320",
                    "362880", "3628800", "39916800", "479001600"
                   };
    int n;
    scanf("%d", &n);
    puts(f[n]);
    return 0;
}
