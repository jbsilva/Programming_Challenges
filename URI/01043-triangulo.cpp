// ============================================================================
// 
//       Filename:  01043-triangulo.cpp
// 
//    Description:  URI 1040 - Média 3
// 
//        Version:  1.0
//        Created:  09/27/2012 08:25:00 AM
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
    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << setprecision(1);
    if (a+b > c && a+c > b && b+c > a)
        cout << "Perimetro = " << a+b+c << endl;
    else
        cout << "Area = " << (a+b)*c/2 << endl;

    return 0;
}
