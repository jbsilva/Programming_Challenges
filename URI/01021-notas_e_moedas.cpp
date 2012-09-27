// ============================================================================
// 
//       Filename:  01021-notas_e_moedas.cpp
// 
//    Description:  URI 1021 - Notas e Moedas
// 
//        Version:  1.0
//        Created:  09/26/2012 11:32:29 PM
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
    double valor;
    cin >> valor;

    int n = 100*valor; // centavos

    cout << "NOTAS:" << endl;
    int x = n/10000; n -= x*10000;
    cout << x << " nota(s) de R$ 100.00" << endl;
    x = n/5000; n -= x*5000;
    cout << x << " nota(s) de R$ 50.00" << endl;
    x = n/2000; n -= x*2000;
    cout << x << " nota(s) de R$ 20.00" << endl;
    x = n/1000; n -= x*1000;
    cout << x << " nota(s) de R$ 10.00" << endl;
    x = n/500; n -= x*500;
    cout << x << " nota(s) de R$ 5.00" << endl;
    x = n/200; n -= x*200;
    cout << x << " nota(s) de R$ 2.00" << endl;

    cout << "MOEDAS:" << endl;
    x = n/100; n -= x*100;
    cout << x << " moeda(s) de R$ 1.00" << endl;
    x = n/50; n -= x*50;
    cout << x << " moeda(s) de R$ 0.50" << endl;
    x = n/25; n -= x*25;
    cout << x << " moeda(s) de R$ 0.25" << endl;
    x = n/10; n -= x*10;
    cout << x << " moeda(s) de R$ 0.10" << endl;
    x = n/5; n -= x*5;
    cout << x << " moeda(s) de R$ 0.05" << endl;
    cout << n << " moeda(s) de R$ 0.01" << endl;

    return 0;
}
