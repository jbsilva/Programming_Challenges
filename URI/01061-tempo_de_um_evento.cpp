// ============================================================================
//
//       Filename:  01061-tempo_de_um_evento.cpp
//
//    Description:  URI 1061 - Tempo de um Evento
//
//        Version:  1.0
//        Created:  09/29/2012 02:57:08 AM
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
    int di, hi, mi, si;
    int df, hf, mf, sf;
    scanf("Dia %d\n", &di);
    scanf("%d : %d : %d\n", &hi, &mi, &si);
    scanf("Dia %d", &df);
    scanf("%d : %d : %d", &hf, &mf, &sf);
    int s1 = (di - 1) * 24 * 3600 + hi * 3600 + mi * 60 + si;
    int s2 = (df - 1) * 24 * 3600 + hf * 3600 + mf * 60 + sf;
    int diff = s2 - s1;
    int x = diff / (24 * 3600); diff -= x * 24 * 3600;
    printf("%d dia(s)\n", x);
    x = diff / 3600; diff -= x * 3600;
    printf("%d hora(s)\n", x);
    x = diff / 60; diff -= x * 60;
    printf("%d minuto(s)\n", x);
    printf("%d segundo(s)\n", diff);
    return 0;
}
