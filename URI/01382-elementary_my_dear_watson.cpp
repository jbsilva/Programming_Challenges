// ============================================================================
//
//       Filename:  01382-elementary_my_dear_watson.cpp
//
//    Description:  URI 1382 - Elementary, my Dear Watson!
//                  
//                  Semelhante a:
//                      "UVa 11495 - Bubbles and Buckets";
//                      "UVa 299 - Train Swapping";
//                      "UVa 12488 - Start Grid".
//                  Mas os elementos não precisam ser consecutivos.
//
//        Version:  1.0
//        Created:  02/May/2013 01:25:08
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


int cases, tam, trocas, a[10100], pos[10100];


// Este selection sort é O(n) e não O(n^2), pois leva em consideração que eu
// consigo determinar a posição do menor elemento em O(1).
inline void selection_sort()
{
    trocas = 0;
    for (int i = 1; i < tam; i++)
        if (a[i] != i)
        {
            a[pos[i]] = a[i];
            pos[a[i]] = pos[i];
            a[i] = i;
            //pos[i] = i;
            trocas++;
        }
}


int main()
{
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &tam);
        for (int i = 1; i <= tam; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }
        selection_sort();
        printf("%d\n", trocas);
    }

    return 0;
}

