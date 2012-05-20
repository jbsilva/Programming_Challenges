// =====================================================================================
// 
//       Filename:  10205-stack_up.cpp
// 
//    Description:  UVA 10205 
// 
//        Version:  1.0
//        Created:  03/24/2011 09:45:10 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

void inicia_baralho(string cartas[53])
{
    string naipe[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    string valor[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    // Numera as cartas de 1 a 52 e atribui os nomes
    int count = 1;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<13; j++)
            cartas[count++] = valor[j] + " of " + naipe[i];
    }
}

int main()
{
    int casos, rodada, n, i,j, num_do_embaralhamento;
    string cartas[53];
    int embaralhamento[101][53];
    int estado_atual[53], proximo_estado[53];

    // Inicia o baralho. Ordenado alfabeticamente por naipe e depois por valor (em inglês)
    inicia_baralho(cartas);

    // Numero de casos
    cin >> casos;

    for (rodada=0; rodada<casos; rodada++)
    {
        cin >> n;
        
        // Pega os n tipos de embaralhamento
        for (i=1; i<=n; i++)
        {
            for (j=1; j<=52; j++)
                cin >> embaralhamento[i][j];
        }
        getchar();

        // Inicia o estado atual
        for (i=1; i<=52; i++)
            estado_atual[i] = i;

        // Aplica os embaralhamentos na ordem indicada.
        // Uso um while, pois o dealer pode saber n embaralhamentos mas só executar alguns
        //while (cin >> num_do_embaralhamento)

        char buffer [10];
        while (fgets(buffer, 10, stdin) != NULL && buffer[0] != '\n')
        {
            num_do_embaralhamento = atoi (buffer);
            for (i=1; i<=52; i++)
                proximo_estado[i] = estado_atual[embaralhamento[num_do_embaralhamento][i]];

            for (i=1; i<=52; i++)
                estado_atual[i] = proximo_estado[i];
        }

        // Rodadas sao separadas por linha em branco
        if (rodada > 0)
            cout << endl;

        for (i=1; i<=52; i++)
            cout << cartas[estado_atual[i]] << endl;
    }

    return 0;
}
