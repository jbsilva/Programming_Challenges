// =====================================================================================
// 
//       Filename:  00100-3nplus1.cpp
// 
//    Description:  UVA 100
//
//                  Versão 1.1:
//                              Apaguei comentários desnecessários
//                              Exclui biblioteca cstdlib desnecessária
// 
//        Version:  1.1
//        Created:  03/17/2011 09:02:26 PM
//       Revision:  14/04/2011 by Julio
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <map>
using namespace std;

typedef unsigned long int ULI;

int cycle_length(ULI n)
{
    int contador = 1;

    while ( n != 1)
    {
        if ( n%2 != 0 )
            n = 3*n+1;
        else
            n = n/2;

        contador++;
    }

    return contador;
}

ULI menor(ULI i, ULI j)
{
    if ( i <= j )           // se forem iguais pode retornar qualquer um
        return i;
    else
        return j;
}

ULI maior(ULI i, ULI j)
{
    if ( i >= j )           // se forem iguais pode retornar qualquer um
        return i;
    else
        return j;
}

int main()
{
    ULI i, j, k;
    map<int,int> comprimentos;

    while ( cin >> i >> j )
    {
        // Limpa o mapa, para receber entradas novas
        comprimentos.clear();

        for ( k = menor(i,j); k <= maior(i,j); k++)
        {
            // Associei dessa forma, pois o mapa já fica ordenado
            comprimentos[cycle_length(k)] = k;
        }
            cout << i << " " << j << " " << (--comprimentos.end())->first << endl;
    }

    return 0;
}
