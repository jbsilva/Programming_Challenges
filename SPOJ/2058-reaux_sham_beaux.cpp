// ============================================================================
//
//       Filename:  roshambo.cpp
//
//    Description:  Reaux! Sham! Beaux!
//                  spoj.pl/problems/CERC07R/
//                  Quase tomou TLE por usar stringstream e muitas strings...
//
//        Version:  1.0
//        Created:  09/04/2012 03:46:53 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

#define dbg if(0)

int main()
{
    int game_num = 0;
    int pts1, pts2;
    // jogadas
    enum jogada { PEDRA, TESOURA, PAPEL };
    map<string, int> j;
    j["Kamen"] = j["Rock"] = j["Pierre"] = j["Stein"] = j["Ko"] = j["Koe"] =
            j["Sasso"] = j["Roccia"] = j["Guu"] = j["Kamien"] = j["Piedra"] = PEDRA;
    j["Nuzky"] = j["Scissors"] = j["Ciseaux"] = j["Schere"] = j["Ollo"] =
            j["Olloo"] = j["Forbice"] = j["Choki"] = j["Nozyce"] = j["Tijera"] = TESOURA;
    j["Papir"] = j["Paper"] = j["Feuille"] =  j["Papier"] = j["Papir"] =
            j["Carta"] =  j["Rete"] = j["Paa"] = j["Papier"] =  j["Papel"] = PAPEL;
    string linha = "";
    while (linha != ".")
    {
        pts1 = pts2 = 0;
        string lang1, nome1, lang2, nome2;
        cin >> lang1 >> nome1 >> lang2 >> nome2;
        cin.ignore();
        while (getline(cin, linha))
        {
            if (linha != "-" && linha != ".")
            {
                string s1, s2;
                istringstream iss(linha);
                iss >> s1 >> s2;
                int s_1 = j[s1];
                int s_2 = j[s2];
                if (s_1 == PEDRA && s_2 == TESOURA) pts1++;
                else if (s_1 == PEDRA && s_2 == PAPEL) pts2++;
                else if (s_1 == TESOURA && s_2 == PEDRA) pts2++;
                else if (s_1 == TESOURA && s_2 == PAPEL) pts1++;
                else if (s_1 == PAPEL && s_2 == PEDRA) pts1++;
                else if (s_1 == PAPEL && s_2 == TESOURA) pts2++;
                dbg cout << "s1: " << s1 << ", s2: " << s2 << endl;
                dbg cout << "pts1: " << pts1 << ", pts2: " << pts2 << endl;
            }
            else
            {
                game_num++;
                if (game_num != 1) cout << endl;
                cout << "Game #" << game_num << ":" << endl;
                cout << nome1 << ": " << pts1 << ((pts1 == 1) ? " point" : " points") << endl;
                cout << nome2 << ": " << pts2 << ((pts2 == 1) ? " point" : " points") << endl;
                if (pts1 == pts2)
                    cout << "TIED GAME" << endl;
                else
                    cout << "WINNER: " << ((pts1 > pts2) ? nome1 : nome2) << endl;
                break;
            }
        }
    }
    return 0;
}
