// ============================================================================
//
//       Filename:  01046-tempo_de_jogo.cpp
//
//    Description:  URI 1046 - Tempo de Jogo
//
//        Version:  1.0
//        Created:  09/27/2012 01:34:02 PM
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
    int inicio, fim, tempo = 0;
    cin >> inicio >> fim;
    if (fim < inicio)
    {
        tempo = 24 - inicio + fim;
    }
    else
        tempo = fim - inicio;
    cout << "O JOGO DUROU " << tempo << " HORA(S)" << endl;
    return 0;
}
