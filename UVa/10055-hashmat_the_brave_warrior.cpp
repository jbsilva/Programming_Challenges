// ===================================================================
//
//       Filename:  10055-hashmat_the_brave_warrior.c (UVa)
//                  01198-hashmat_the_brave_warrior.c (URI)
//
//    Description:  UVa 10055 - Hashmat the Brave Warrior
//                  URI 1198 - Hashmat the Brave Warrior
//
//        Version:  1.0
//        Created:  09/19/2012 08:22:03 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ===================================================================
#include <cstdio>

int main()
{
    long long int n1, n2;
    while (scanf("%lld %lld", &n1, &n2) != EOF)
        printf("%lld\n", (n1 > n2 ? n1 - n2 : n2 - n1));
    return 0;
}
