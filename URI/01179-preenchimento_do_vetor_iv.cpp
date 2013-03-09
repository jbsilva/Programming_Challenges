// ============================================================================
//
//       Filename:  01179-preenchimento_do_vetor_iv.cpp
//
//    Description:  URI 1179 - Preenchimento do Vetor IV
//
//        Version:  1.0
//        Created:  09/28/2012 02:48:28 PM
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
    int par[7], impar[7];
    int i_par = 0, i_impar = 0;
    int n;
    for (int i = 0; i < 15; i++)
    {
        cin >> n;
        if (n % 2 == 0)
        {
            par[i_par] = n;
            i_par++;
            if (i_par == 5)
            {
                for (int j = 0; j < 5; j++)
                    cout << "par[" << j << "] = " << par[j] << endl;
                i_par = 0;
            }
        }
        else
        {
            impar[i_impar] = n;
            i_impar++;
            if (i_impar == 5)
            {
                for (int j = 0; j < 5; j++)
                    cout << "impar[" << j << "] = " << impar[j] << endl;
                i_impar = 0;
            }
        }
    }
    for (int i = 0; i < i_impar; i++)
        cout << "impar[" << i << "] = " << impar[i] << endl;
    for (int i = 0; i < i_par; i++)
        cout << "par[" << i << "] = " << par[i] << endl;
    return 0;
}
