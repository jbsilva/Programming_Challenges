// ============================================================================
// 
//       Filename:  5484-escultura_a_laser.cpp (SPOJ BR)
//                  11683-laser_sculpture.cpp (UVA)
//                  01107-escultura_a_laser.cpp (URI)
// 
//    Description:  SPOJ BR 5484 - Escultura a Laser
//                  UVA 11683 - Laser Sculpture
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
    int alt, comp;
    int af[10001];
    while (scanf("%d %d", &alt, &comp) && (alt || comp))
    {
        //int af[comp+1]; // altura final
        for (int i = 0; i < comp; i++)
            scanf("%d", &af[i]);
        af[comp] = alt; // Cria último bloco imaginário

        int vezes = 0;
        for (int i = alt; i > 0; i--)
        {
            // Bloco da esquerda > altura i atual? Cria 1o bloco imaginário.
            bool anterior = true;
            for (int j = 0; j <= comp; j++)
            {
                if (af[j] >= i)
                {
                    if (!anterior)
                    {
                        vezes++;
                        anterior = true;
                    }
                }
                else
                    anterior = false;
            }
        }

        printf("%d\n", vezes);
    }

    return 0;
}
