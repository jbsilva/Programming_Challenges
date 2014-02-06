// ============================================================================
//
//       Filename:  11727-cost_cutting.cpp
//
//    Description:  UVa 11727 - Cost Cutting
//
//                  Usar 'nth_element' neste problema é overkill, mas o código
//                  fica curto e fácil de modificar caso fossem mais de 3
//                  elementos.
//
//        Version:  1.0
//        Created:  06/Feb/2014 22:02:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    int T, v[3];
    scanf("%d", &T);
    for (int caso = 1; caso <= T; caso++)
    {
        scanf("%d %d %d", &v[0], &v[1], &v[2]);
        nth_element(v, v + 1, v + 3);
        printf("Case %d: %d\n", caso, v[1]);
    }
    return 0;
}

