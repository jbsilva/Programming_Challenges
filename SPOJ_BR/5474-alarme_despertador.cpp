// ============================================================================
//
//       Filename:  5474-alarme_despertador.cpp (SPOJ BR)
//                  01103-alarme_despertador.cpp (URI)
//
//    Description:  Alarme despertador
//                  br.spoj.pl/problems/ALADES/
//
//        Version:  1.0
//        Created:  08/12/2012 01:50:44 PM
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
    int h1, m1, h2, m2, t1, t2, delta;
    while (cin >> h1 >> m1 >> h2 >> m2 && (h1 || m1 || h2 || m2))
    {
        t1 = 60 * h1 + m1;
        t2 = 60 * h2 + m2;
        delta = t2 - t1;
        if (delta < 0)
            cout << 1440 - t1 + t2 << endl;
        else
            cout << delta << endl;
    }
    return 0;
}
