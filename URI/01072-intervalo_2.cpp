// ============================================================================
// 
//       Filename:  01072-intervalo_2.cpp
// 
//    Description:  URI 1072 - Intervalo 2
// 
//        Version:  1.0
//        Created:  09/29/2012 06:59:59 PM
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

    int x, in=0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);

        if (x >= 10 && x <= 20)
            in++;
    }

    printf("%d in\n%d out\n", in, n-in);

    return 0;
}
