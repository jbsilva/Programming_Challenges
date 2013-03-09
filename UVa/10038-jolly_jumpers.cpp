// ============================================================================
//
//       Filename:  10038-jolly_jumpers.cpp
//
//    Description:  10038 - Jolly Jumpers
//
//        Version:  1.0
//        Created:  09/22/2012 10:03:49 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool diffs[3002];
    int n, anterior, atual;
    while (cin >> n)
    {
        memset(diffs, 0, sizeof(diffs));
        cin >> anterior;
        for (int i = 1; i < n; i++)
        {
            cin >> atual;
            int d = atual > anterior ? atual - anterior : anterior - atual;
            diffs[d] = 1;
            anterior = atual;
        }
        bool jolly = true;
        for (int i = 1; i < n; i++)
            if (!diffs[i])
            {
                jolly = false;
                break;
            }
        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
