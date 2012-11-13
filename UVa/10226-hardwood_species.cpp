// ============================================================================
// 
//       Filename:  10226-hardwood_species.cpp (UVa)
//                  01260-hardwood_species.cpp (URI)
// 
//    Description:  UVa 10226 - Hardwood Species
//                  URI 1260 - Hardwood Species
// 
//        Version:  1.0
//        Created:  13/Nov/2012 14:00:42
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;


int main()
{
    int cases, arvores;
    string spc;
    map<string, int> especies;
    map<string, int>::iterator it;

    cin >> cases;
    cin.ignore(256, '\n'); // ignora o \n
    cin.ignore(256, '\n'); // ignora a linha em branco

    while (cases--)
    {
        arvores = 0;
        while (getline(cin, spc) && spc != "")
        {
            especies[spc]++;
            arvores++;
        }

        for (it = especies.begin(); it != especies.end(); it++)
            printf("%s %.4f\n", (it->first).data(), 100.0 * it->second/arvores);

        if (cases) cout << "\n";

        especies.clear();
    }

    return 0;
}
