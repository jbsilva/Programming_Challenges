// ============================================================================
// 
//       Filename:  01177-preenchimento_de_vetor_ii.cpp
// 
//    Description:  URI 1177 - Preenchimento de Vetor II
// 
//        Version:  1.0
//        Created:  09/28/2012 03:38:35 PM
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
    int t;
    cin >> t;

    for (int i=0; i < 1000; i++)
    {
        cout << "N[" << i << "] = " << i%t << endl;
    }
    return 0;
}
