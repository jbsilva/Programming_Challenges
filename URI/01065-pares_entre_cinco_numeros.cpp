// ============================================================================
// 
//       Filename:  01065-pares_entre_cinco_numeros.cpp
// 
//    Description:  URI 1065 - Pares entre Cinco Números
// 
//        Version:  1.0
//        Created:  09/29/2012 04:09:47 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
using namespace std;

int main()
{
    int n, pares=0;
    for (int i=0; i<5; i++)
    {
        cin >> n;
        if (n%2 == 0)
            pares++;
    }

    cout << pares << " valores pares" << endl;

    return 0;
}
