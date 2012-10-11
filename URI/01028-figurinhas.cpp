// ============================================================================
// 
//       Filename:  01028-figurinhas.cpp
// 
//    Description:  URI 1028 - Figurinhas
// 
//        Version:  1.0
//        Created:  11/Oct/2012 10:36:53
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

typedef unsigned int UI;

UI mdc(UI a, UI b)
{
    while (b > 0)
    {
        a = a % b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int main()
{
    UI cases, f1, f2;

    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%u %u", &f1, &f2);
        printf("%u\n", mdc(f1, f2));
    }

    return 0;
}
