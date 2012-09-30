// ============================================================================
// 
//       Filename:  01078-tabuada.cpp
// 
//    Description:  URI 1078 - Tabuada
// 
//        Version:  1.0
//        Created:  09/29/2012 07:33:23 PM
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

    for (int i=1; i<=10; i++)
        printf("%d x %d = %d\n", i, n, i*n);

    return 0;
}
