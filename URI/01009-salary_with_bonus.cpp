// ============================================================================
// 
//       Filename:  01009-salary_with_bonus.cpp
// 
//    Description:  URI 1009 - Salary with Bonus
// 
//        Version:  1.0
//        Created:  09/26/2012 10:17:57 PM
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
    string nome;
    double salary, sold;

    cin >> nome >> salary >> sold;
    cout << fixed << setprecision(2)
         << "TOTAL = R$ " << salary + 0.15*sold << endl;

    return 0;
}
