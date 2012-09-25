// ============================================================================
// 
//       Filename:  00750-8_queens_chess_problem.cpp
// 
//    Description:  UVa 750 - 8 Queens Chess Problem
//                  Solução baseada no Competitive Programming 2ed
//                  Ainda da para otimizar mais
// 
//        Version:  1.0
//        Created:  09/24/2012 09:27:33 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;

int linha[9]; // guarda a resposta (linha[x] é a linha da coluna x com rainha)
int l, c; // posicao da rainha do enunciado
int count; 

// Verifica se é seguro posicionar uma raina na linha e coluna indicada
bool seguro(int col, int lin)
{
    for (int i = 1; i < col; i++)
        if (linha[i] == lin || (abs(linha[i] - lin) == abs(i - col)))
            return false; // já tem rainha na mesma linha ou diagonal
    return true;
}

void backtrack(int col)
{
    for (int lin = 1; lin <= 8; lin++)
    {
        if (seguro(col, lin))
        {
            linha[col] = lin;
            if (col == 8 && linha[c] == l)
            {
                cout << setw(2) << ++count << "      " << linha[1];
                for (int j = 2; j <= 8; j++)
                    cout << " " << linha[j];
                cout << endl;
            }
            else
                backtrack(col+1);
        }
    }
}

int main()
{
    int datasets;
    cin >> datasets;

    while (datasets--)
    {
        memset(linha, 0, sizeof linha);
        count = 0;

        cin >> l >> c;
        linha[c] = l;

        cout << "SOLN       COLUMN\n"
             << " #      1 2 3 4 5 6 7 8\n\n";

        backtrack(1); // começa backtrack a partir da 1a coluna
        if (datasets) cout << "\n"; // último caso não tem \n
    }

    return 0;
}
