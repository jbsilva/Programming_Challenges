// ============================================================================
// 
//       Filename:  11496-musical_loop.cpp
//                  3242-loop_musical.cpp
// 
//    Description:  UVa 11496 - Musical Loop
//                  SPOJ BR 3242 - Loop Musical
//                  br.spoj.pl/problems/LOOPMUSI/
//
//                  Primeira fase da Maratona de Programação 2008
// 
//        Version:  1.0
//        Created:  09/28/2012 07:29:48 PM
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
    int samples, peaks, primeiro, anterior, atual;
    bool subindo, primeiro_subindo;
    while (cin >> samples && samples)
    {
        cin >> primeiro;
        cin >> atual; 

        primeiro_subindo = subindo =  atual > primeiro ? true : false;
        anterior = atual;

        peaks = 1;
        for (int i=2; i < samples; i++)
        {
            cin >> atual;

            if (anterior < atual && !subindo)
            {
                peaks++;
                subindo = true;
            }
            else if (anterior > atual && subindo)
            {
                peaks++;
                subindo = false;
            }
            anterior = atual;
        }

        if (atual < primeiro && !subindo)
        {
            peaks++;
            subindo = true;
        }
        else if (atual > primeiro && subindo)
        {
            peaks++;
            subindo = false;
        }

        if (subindo == primeiro_subindo)
            peaks--;

        cout << peaks << endl;
    }

    return 0;
}
