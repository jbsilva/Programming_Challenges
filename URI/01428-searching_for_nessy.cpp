// ============================================================================
// 
//       Filename:  01428-searching_for_nessy.cpp
// 
//    Description:  URI 1428 - Searching for Nessy.cpp
//
//                  Resolvido durante a seletiva ICMC de 2012
// 
//        Version:  1.0
//        Created:  08/25/2012 11:16:33 AM
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
    int testes;
    cin >> testes;

    int lin, col;
    while (testes--)
    {
        cin >> lin >> col;

        int l;
        if ( (lin-2)%3 != 0)
            l = (lin-2)/3 + 1;
        else
            l = (lin-2)/3;

        int c;
        if ( (col-2)%3 != 0)
            c = (col-2)/3 + 1;
        else
            c = (col-2)/3;

        cout << l*c << endl;
    }

    return 0;
}

