// ============================================================================
//
//       Filename:  00146-id_codes.cpp
//
//    Description:  UVa 146 - ID Codes
//
//        Version:  1.0
//        Created:  06/Feb/2014 21:43:18
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    string id;
    while (getline(cin, id) && id != "#")
    {
        if (next_permutation(id.begin(), id.end()))
            cout << id << endl;
        else
            cout << "No Successor\n";
    }
    return 0;
}

