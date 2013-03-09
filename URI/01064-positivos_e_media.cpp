// ============================================================================
//
//       Filename:  01064-positivos_e_media.cpp
//
//    Description:  URI 1064 - Positivos e Média
//
//        Version:  1.0
//        Created:  09/29/2012 04:04:10 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double n, pos = 0, sum = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> n;
        if (n > 0)
        {
            pos++;
            sum += n;
        }
    }
    cout << pos << " valores positivos" << endl
         << fixed << setprecision(1) << sum / pos << endl;
    return 0;
}
