// ============================================================================
//
//       Filename:  12289-one_two_three.cpp (UVa)
//                  01332-one_two_three.cpp (URI)
//
//    Description:  UVa 12289 - One-Two-Three
//                  URI 1332 - One-Two-Three
//
//        Version:  1.0
//        Created:  26/Apr/2013 18:30:48
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


char p[6];


inline int dist_one()
{
    int dist = 0;

    if (p[0] != 'o') dist++;
    if (p[1] != 'n') dist++;
    if (p[2] != 'e') dist++;

    return dist;
}


int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        scanf("%s", p);

        if (strlen(p) != 3)
            puts("3");
        else
        {
            if (dist_one() <= 1)
                puts("1");
            else
                puts("2");
        }
    }

    return 0;
}

