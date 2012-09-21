// ===================================================================
// 
//       Filename:  10055-hashmat_the_brave_warrior.cpp
// 
//    Description:  10055 - Hashmat the Brave Warrior
// 
//        Version:  1.0
//        Created:  09/19/2012 08:22:03 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ===================================================================
#include <iostream>
using namespace std;

int main()
{
    long long int n1, n2;
    while (cin >> n1 >> n2)
        cout << (n1>n2 ? n1-n2 : n2-n1) << endl;

    return 0;
}
