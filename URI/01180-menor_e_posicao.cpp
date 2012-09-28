// ============================================================================
// 
//       Filename:  01180-menor_e_posicao.cpp
// 
//    Description:  1180 - Menor e Posição
// 
//        Version:  1.0
//        Created:  09/28/2012 02:34:47 PM
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
    int n;
    cin >> n;

    int v, index=0, min=0x3f3f3f3f;
    for (int i=0; i<n ; i++)
    {
        cin >> v;
        if (v < min)
        {
            min = v;
            index = i;
        }
    }

    cout << "Menor valor: " << min << endl;
    cout << "Posicao: " << index << endl;

    return 0;
}
