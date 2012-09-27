// ============================================================================
// 
//       Filename:  01019-conversao_de_tempo.cpp
// 
//    Description:  URI 1019 - Conversão de tempo
// 
//        Version:  1.0
//        Created:  09/26/2012 11:23:08 PM
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
    int s;
    cin >> s;

    int h = s/3600; s -= 3600*h;
    int m = s/60; s -= 60*m;

    cout << h << ":" << m << ":" << s << endl;

    return 0;
}
