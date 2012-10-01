// ============================================================================
// 
//       Filename:  01142-pum.cpp
// 
//    Description:  URI 1142 - PUM
// 
//        Version:  1.0
//        Created:  09/30/2012 03:35:55 PM
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
    int lins;
    scanf("%d", &lins);

    int i = 1;
    while (lins--)
    {
        printf("%d %d %d PUM\n", i, i+1, i+2);
        i+= 4;
    }

    return 0;
}
