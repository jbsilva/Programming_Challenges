// ============================================================================
//
//       Filename:  01047-tempo_de_jogo_com_minutos.cpp
//
//    Description:  URI 1047 - Tempo de Jogo com Minutos
//
//        Version:  1.0
//        Created:  09/28/2012 08:21:54 AM
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
    int hi, hf, mi, mf;
    cin >> hi >> mi >> hf >> mf;
    int ti = hi * 60 + mi;
    int tf = hf * 60 + mf;
    int mins;
    if (tf < ti)
        mins = 24 * 60 - ti + tf;
    else
        mins = tf - ti;
    int hp = mins / 60;
    int mp = mins - 60 * hp;
    cout << "O JOGO DUROU " << hp << " HORA(S) E " << mp << " MINUTO(S)" << endl;
    return 0;
}

