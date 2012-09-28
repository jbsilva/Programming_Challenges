// ============================================================================
// 
//       Filename:  01042-sort_simples.cpp
// 
//    Description:  URI 1042 - Sort Simples
// 
//        Version:  1.0
//        Created:  09/27/2012 08:20:00 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int v[3], o[3];

    cin >> v[0] >> v[1] >> v[2];
    memcpy(o, v, sizeof(v));

    sort(o, &o[3]);

    for (int i=0; i < 3; i++)
        cout << o[i] << endl;
    cout << endl;

    for (int i=0; i < 3; i++)
        cout << v[i] << endl;

    return 0;
}
