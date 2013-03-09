// ============================================================================
//
//       Filename:  10281-average_speed.cpp (UVa)
//                  02501-average_speed.cpp (POJ)
//                  01304-average_speed.cpp (URI)
//
//    Description:  UVa 10281 - Average Speed
//                  POJ 2501 - Average Speed
//                  URI 1304 - Average Speed
//
//                    Input                       Output
//                    00:08:01                    00:08:01 0.00 km
//                    00:10:01   50               00:31:10 17.62 km
//                    00:31:10                    99:59:59 197466111174.97 km
//                    01:10:05 140
//                    01:16:00 2000000000
//                    99:59:59
//
//                    Após corrigirem os inputs no URI, a versão 1.0 foi aceita
//                    A 1.5 usa só 1 sscanf e não refaz a conta dos segundos.
//
//        Version:  1.5
//        Created:  03/Mar/2013 21:27:50
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
    char lin[200];
    int h, m, s, v, v2 = 0, sec = 0, sec2 = 0, leu;
    double total = 0.0;
    while (gets(lin) != NULL)
    {
        leu = sscanf(lin, "%d:%d:%d %d", &h, &m, &s, &v);
        sec = h * 3600 + m * 60 + s;
        total += v2 / 3600.0 * (sec - sec2);
        sec2 = sec; v2 = v;
        if (leu == 3)
            printf("%02d:%02d:%02d %.2f km\n", h, m, s, total);
    }
    return 0;
}
