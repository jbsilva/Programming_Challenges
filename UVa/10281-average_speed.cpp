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
//        Version:  1.0 -- ACC no UVa e POJ. WA no URI (investigando o motivo)
//        Created:  03/Mar/2013 21:27:50
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>


int main()
{
    char lin[200];
    int h1, m1, s1, h2, m2, s2, diff, speed;
    double total = 0.0;
    h2 = m2 = s2 = speed = 0;

    while (gets(lin) != NULL)
    {
        sscanf(lin, "%d:%d:%d", &h1, &m1, &s1);
        diff = (h1*3600 + m1*60 + s1) - (h2*3600 + m2*60 + s2);
        total += speed / 3600.0 * diff;

        // Se o scanf retornar EOF, então os caracteres extras eram só espaços.
        if (!(strlen(lin) > 8 && sscanf(lin+9, "%d", &speed) != EOF))
            printf("%02d:%02d:%02d %.2f km\n", h1, m1, s1, total);

        h2 = h1; m2 = m1; s2 = s1;
    }

    return 0;
}

