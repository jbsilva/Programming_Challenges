// ============================================================================
//
//       Filename:  01013-o_maior.cpp
//
//    Description:  URI 1013 - O Maior
//
//        Version:  1.0
//        Created:  09/26/2012 10:52:10 PM
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
    int n, maior;
    cin >> n;
    maior = n;
    for (int i = 1; i < 3; i++)
    {
        cin >> n;
        if (n > maior)
            maior = n;
    }
    cout << maior << " eh o maior" << endl;
    return 0;
}
