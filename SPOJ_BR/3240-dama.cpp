// ============================================================================
// 
//       Filename:  3240-dama.cpp
// 
//    Description:  br.spoj.pl/problems/DAMA/
//                  Primeira fase da Maratona de Programação - 2008
// 
//        Version:  1.0
//        Created:  09/13/2012 09:44:33 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
using namespace std;

inline int abs(int a)
{
    return a<0 ? -1*a : a;
}

int main()
{
    int x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2 && (x1 || y1 || x2 || y2))
    {
        // mesma casa
        if (x1 == x2 && y1 == y2)
            cout << 0 << endl;
        // está na mesma linha ou mesma coluna
        else if (x1 == x2 || y1 == y2)
            cout << 1 << endl;
        // mesma diagonal
        else if (abs(x2 - x1) == abs(y2 - y1))
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
