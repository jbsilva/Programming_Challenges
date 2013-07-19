// ============================================================================
//
//       Filename:  00483-word_scramble.cpp
//
//    Description:  UVa 483 - Word Scramble
//
//        Version:  1.0
//        Created:  19/Jul/2013 15:13:06
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main()
{
    string lin, pal;
    istringstream iss;

    while (getline(cin, lin))
    {
        bool first = true;

        iss.clear();
        iss.str(lin);

        while (iss >> pal)
        {
            reverse(pal.begin(), pal.end());

            if (!first) cout << " ";
            first = false;

            cout << pal;
        }
        
        cout << endl;
    }

    return 0;
}

