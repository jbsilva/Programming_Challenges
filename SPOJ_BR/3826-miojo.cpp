// ============================================================================
//
//       Filename:  3826-miojo.cpp
//
//    Description:  br.spoj.pl/problems/MIOJO
//
//        Version:  1.0
//        Created:  08/27/2012 12:10:49 AM
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
    int preparo, amp_a, amp_b;
    while (cin >> preparo >> amp_a >> amp_b)
    {
        int a = amp_a; int b = amp_b; // quanto tempo ainda tem nas ampulhetas
        int total = 0;
        while (a != preparo && b != preparo)
        {
            if (a < b)
            {
                total += a;
                b -= a;     // sobrou b-a min
                a = amp_a;  // virou amp_a
            }
            else
            {
                total += b;
                a -= b;
                b = amp_b;
            }
        }
        cout << total + preparo << endl;
    }
    return 0;
}
