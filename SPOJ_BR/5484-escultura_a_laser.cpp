// ============================================================================
//
//       Filename:  5484-escultura_a_laser.cpp (SPOJ BR)
//                  11683-laser_sculpture.cpp (UVa)
//                  01107-escultura_a_laser.cpp (URI)
//
//    Description:  SPOJ BR 5484 - Escultura a Laser
//                  UVa 11683 - Laser Sculpture
//                  URI 1107 - Escultura a Laser
//
//                  br.spoj.pl/problems/LASERR/
//                  Primeira Fase da Maratona de Programação 2009
//
//        Version:  1.0
//        Created:  04/Dec/2012 01:21:01
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
    int alt, comp, vezes, inicial, anterior, atual;
    while (scanf("%d %d", &alt, &comp) && (alt || comp))
    {
        vezes = 0;
        inicial = anterior = alt;
        bool subindo = false;
        for (int i = 0; i < comp; i++)
        {
            scanf("%d", &atual);
            if (atual < anterior)
            {
                subindo = false;
            }
            else if (atual > anterior)
            {
                if (!subindo)
                    vezes += inicial - anterior;
                inicial = atual;
                subindo = true;
            }
            anterior = atual;
        }
        if (!subindo)
            vezes += inicial - anterior;
        printf("%d\n", vezes);
    }
    return 0;
}
