// =====================================================================================
// 
//       Filename:  10026-shoemaker.cpp
// 
//    Description:  UVA 10026
// 
//        Version:  1.0
//        Created:  04/03/2011 07:23:08 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define USI unsigned short int

// =====================================================================================
//        Class:  Jobs
//  Description:  Cada objeto é um trabalho 
// =====================================================================================
#ifndef JOBS_H
#define JOBS_H

class Jobs
{
    public:
            USI Posicao;
            double Razao;

            Jobs(USI, USI, USI);
};

#endif

// Construtor
Jobs::Jobs(USI posicao, USI tempo, USI pena)
    : Posicao(posicao)
{
    Razao = (double)pena/tempo;
}

// Funçao para comparar
bool compara(Jobs a, Jobs b)
{
    if (a.Razao > b.Razao)
        return true;
    else
        return false;
}

int main()
{
    USI cases, n, i, tempo, pena;
    vector<Jobs> trabalhos;

    cin >> cases;
    cin.ignore(2);

    while (cases--)
    {
        cin >> n;

        for (i=1; i<=n; i++)
        {
            cin >> tempo >> pena;

            Jobs temp(i,tempo,pena);

            trabalhos.push_back(temp);
        }

        // Ordena o vetor pela pena/tempo.
        // Quanto maior essa razão, mais rápido o trabalho deve ser executado
        stable_sort( trabalhos.begin() , trabalhos.end(), compara );
        
        for (i=0; i<trabalhos.size() - 1; i++)
            cout << trabalhos[i].Posicao << " ";

        cout << trabalhos[trabalhos.size() -1].Posicao << endl;

        trabalhos.clear();

        if (cases != 0)
            cout << endl;
    }

    return 0;
}
