// =====================================================================================
// 
//       Filename:  10041-vito_family.cpp
// 
//    Description:  UVA 10041
// 
//        Version:  1.0
//        Created:  04/02/2011 05:21:02 PM
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

typedef unsigned short int USI;

#if 0
USI Mediana(vector<USI> &casas)
{
    vector<USI>::iterator primeiro, ultimo;

    primeiro = casas.begin();
    ultimo = casas.end();

    // Para número ímpar de casas
    if (casas.size() % 2 == 1)
    {
        vector<USI>::iterator meio = primeiro + distance(primeiro,ultimo) / 2;
        nth_element(primeiro, meio, ultimo);

        return (*meio);
    }
    // Para número par de casas
    else
    {
        vector<USI>::iterator meio1 = primeiro + distance(primeiro,ultimo) / 2;
        nth_element(primeiro, meio1, ultimo);

        vector<USI>::iterator meio2 = primeiro + ( distance(primeiro,ultimo) - 1) / 2;
        nth_element(primeiro, meio2, ultimo);

        return (*meio1 + *meio2) / 2;
    }
}
#endif

USI Mediana( vector<USI> &vetor)
{
    sort(vetor.begin(), vetor.end());
    
    return vetor.at(vetor.size()/2);
}

USI distancia(USI s1, USI s2)
{
    if (s1 > s2)
        return (s1 - s2);
    else
        return (s2 - s1);
}

int main()
{
    USI casos, r, i, num, mediana;
    int soma;

    vector<USI> casas;
    vector<USI>::iterator it;

    cin >> casos;

    while (casos--)
    {
        cin >> r;

        for (i=0; i<r; i++)
        {
            cin >> num;

            // Insere o numero da casa ao vetor
            casas.push_back(num);
        }

        mediana = Mediana(casas);
        soma = 0;

        for ( it=casas.begin(); it != casas.end(); it++)
            soma += distancia(mediana,*it);

        cout << soma << endl;

        casas.clear();
    }

    return 0;
}
