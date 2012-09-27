// ============================================================================
// 
//       Filename:  01020-idade_em_dias.cpp
// 
//    Description:  URI 1020 - Idade em Dias
// 
//        Version:  1.0
//        Created:  09/26/2012 11:26:21 PM
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
    int d;
    cin >> d;

    int a = d/365; d -= 365*a;
    int m = d/30; d -= 30*m;

    cout << a << " ano(s)" << endl;
    cout << m << " mes(es)" << endl;
    cout << d << " dia(s)" << endl;

    return 0;
}
