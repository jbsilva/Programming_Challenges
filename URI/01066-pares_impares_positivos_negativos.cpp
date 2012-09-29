// ============================================================================
// 
//       Filename:  01066-pares_impares_positivos_negativos.cpp
// 
//    Description:  URI 1066 - Pares, Ímpares, Positivos e Negativos
// 
//        Version:  1.0
//        Created:  09/29/2012 04:13:15 PM
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
    int n, pares=0, pos=0, neg=0;
    for (int i=0; i<5; i++)
    {
        cin >> n;

        if (n%2 == 0)
            pares++;

        if (n>0)
            pos++;
        else if (n<0)
            neg++;
    }

    cout << pares << " valor(es) par(es)" << endl
         << 5-pares << " valor(es) impar(es)" << endl
         << pos << " valor(es) positivo(s)" << endl
         << neg << " valor(es) negativo(s)" << endl;

    return 0;
}
