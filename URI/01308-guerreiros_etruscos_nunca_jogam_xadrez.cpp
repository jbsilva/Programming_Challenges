// ============================================================================
//
//       Filename:  01308-guerreiros_etruscos_nunca_jogam_xadrez.cpp
//
//    Description:  URI 1308 - Guerreiros Etruscos Nunca Jogam Xadrez
//
//                  Usei a fórmula de progressão aritmética:
//                      1+2+...+f=n  =>  (1+f)*(f/2)=n  =>  f=(sqrt(1+8*n)-1)/2
//
//        Version:  1.0
//        Created:  15/Mar/2013 18:56:59
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cmath>

int main()
{
    double n, EPS = 10E-6; // EPS é para caso o sqrt arredonde para baixo
    int casos;

    scanf("%d", &casos);
    while (casos--)
    {
        scanf("%lf", &n);
        printf("%d\n", (int)((sqrt(1 + 8*n)+EPS - 1.0) / 2.0));
    }

    return 0;
}

