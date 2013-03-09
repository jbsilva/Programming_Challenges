// ============================================================================
//
//       Filename:  01150-ultrapassando_z.cpp
//
//    Description:  URI 1150 - Ultrapassando Z
//
//        Version:  1.0
//        Created:  09/30/2012 05:22:35 PM
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
    int x, z;
    scanf("%d", &x);
    do
    {
        scanf("%d", &z);
    }
    while (z < x);
    int i = x + 1, count = 1;
    while (x <= z)
    {
        count++;
        x += i;
        i++;
    }
    printf("%d\n", count);
    return 0;
}
