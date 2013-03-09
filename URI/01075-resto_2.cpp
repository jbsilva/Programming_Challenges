// ============================================================================
//
//       Filename:  01075-resto_2.cpp
//
//    Description:  URI 1075 - Resto 2
//
//        Version:  1.0
//        Created:  09/29/2012 07:18:20 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 0)
        n = -n;
    if (n > 2)
        printf("2\n");
    for (int i = n + 2; i < 10000; i += n)
        printf("%d\n", i);
    return 0;
}
