// ============================================================================
//
//       Filename:  01008-salary.cpp
//
//    Description:  URI 1008 - Salary
//
//        Version:  1.0
//        Created:  09/26/2012 10:13:44 PM
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
    int number, hours;
    double pay;
    cin >> number >> hours >> pay;
    cout << "NUMBER = " << number << endl;
    cout << fixed << setprecision(2) << "SALARY = U$ " << pay* hours << endl;
    return 0;
}
