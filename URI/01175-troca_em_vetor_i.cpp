// ============================================================================
//
//       Filename:  01175-troca_em_vetor_i.cpp
//
//    Description:  URI 1175 - Troca em Vetor I
//
//        Version:  1.0
//        Created:  09/28/2012 04:44:08 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    for (int i = 0; i < 20; i++)
    {
        cin >> n;
        s.push(n);
    }
    int i = 0;
    while (!s.empty())
    {
        cout << "N[" << i << "] = " << s.top() << endl;
        s.pop();
        i++;
    }
    return 0;
}
