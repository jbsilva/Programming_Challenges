// ============================================================================
// 
//       Filename:  5477-troca_de_cartas.cpp (SPOJ BR)
//                  01104-troca_de_cartas.cpp (URI)
// 
//    Description:  SPOJ BR 5477 - Troca de cartas
//                  UVa 1104 - Troca de cartas
//
//                  br.spoj.pl/problems/TROCCARD/
// 
//        Version:  1.0
//        Created:  08/12/2012 05:48:27 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int qtd_a, qtd_b;
    set<int>a;
    set<int>b;
    set<int>inter;
    int i;
    int tam_a, tam_b, menor, temp;

    while (cin >> qtd_a >> qtd_b && (qtd_a || qtd_b))
    {
        a.clear();
        b.clear();
        inter.clear();

        for (i=0; i<qtd_a; i++)
        {
            cin >> temp;
            a.insert(temp);
        }

        for (i=0; i<qtd_b; i++)
        {
            cin >> temp;
            b.insert(temp);
        }

        set_intersection(a.begin(),a.end(), b.begin(), b.end(), inserter(inter, inter.end()));

        tam_a = a.size();
        tam_b = b.size();

        if (tam_a < tam_b)
            menor = tam_a;
        else
            menor = tam_b;

        int qtd = menor - inter.size();
        cout << qtd << endl;
    }

    return 0;
}
