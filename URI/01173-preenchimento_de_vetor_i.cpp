// ============================================================================
//
//       Filename:  01173-preenchimento_de_vetor_i.cpp
//
//    Description:  URI 1173 - Preenchimento de Vetor I
//
//        Version:  1.0
//        Created:  09/28/2012 04:58:12 PM
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
    for (int i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i, n);
        n <<= 1;
    }
    return 0;
}
