// =====================================================================================
// 
//       Filename:  10006-Carmichael_Numbers_v1.cpp
// 
//    Description:  UVA 10006
// 
//        Version:  1.0
//        Created:  05/04/2011 11:32:15 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
using namespace std;

typedef unsigned int UI;

int main()
{
    UI n;

    while (cin >> n && n != 0)
    {
        // Só existem 15 números de Carmichael no intervalo válido para n (2 < n < 65000)
        switch(n)
        {
            case 561:
            case 1105:
            case 1729:
            case 2465:
            case 2821:
            case 6601:
            case 8911:
            case 10585:
            case 15841:
            case 29341:
            case 41041:
            case 46657:
            case 52633:
            case 62745:
            case 63973:
                    cout << "The number " << n << " is a Carmichael number." << endl; break;
            default:
                cout << n << " is normal." << endl;
        }
    }

    return 0;
}
