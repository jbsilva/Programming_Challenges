// ============================================================================
// 
//       Filename:  1891-historico_comandos.cpp
// 
//    Description:  Primeira fase da Maratona de Programação - 2007
//                  br.spoj.pl/problems/HIST/
// 
//        Version:  1.0
//        Created:  09/14/2012 12:02:55 AM
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
    int p[1001];
    int n;
    while (cin >> n && n)
    {
        for (int i=0; i<n; i++)
            cin >> p[i];

        int soma = 0;
        for (int i=0; i<n; i++)
        {
            // Executa proximo comando
            soma += p[i];

            // Muda distancia do comando atual para 1 e incrementa os outros
            for (int j=i+1; j<n; j++)
                if (p[j] != p[i])
                    p[j]++;
                else
                    p[j] = 1;
        }

        cout << soma << endl;
    }
    return 0;
}
