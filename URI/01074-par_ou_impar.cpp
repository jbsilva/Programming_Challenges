// ============================================================================
//
//       Filename:  01074-par_ou_impar.cpp
//
//    Description:  URI 1074 - Par ou Ímpar
//
//        Version:  1.0
//        Created:  09/29/2012 07:10:27 PM
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
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 0)
            printf("NULL\n");
        else
        {
            if (x % 2 == 0)
                printf("EVEN ");
            else
                printf("ODD ");
            if (x < 0)
                printf("NEGATIVE\n");
            else
                printf("POSITIVE\n");
        }
    }
    return 0;
}
