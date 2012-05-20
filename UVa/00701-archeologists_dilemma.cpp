// =====================================================================================
// 
//       Filename:  00701-archeologists_dilemma.cpp
// 
//    Description:  UVA 701
//                  Declarei n como unsigned long int para portabilidade, já que em
//                  algumas arquiteturas o int tem 16 bits e não 32.
// 
//        Version:  1.0
//        Created:  04/09/2011 09:24:50 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long int ULI;
typedef unsigned short int USI;

// Descobre a quantidade de dígitos de um número
inline USI digitos(ULI n, USI base=10)
{
    USI count = 0;
    while (n)
    {
        n /= base;
        count++;
    }

    return count;
}

int main()
{
    ULI n, i;                 // 0 -> 2^32 -1

    while (cin >> n)
    {
        // Se n tem "dig" dígitos, então o número que procuramos está entre n*10^(i) e (n+1)*10^(i).
        // Incrementamos i, iniciando de (dig+1), até a parte inteira de seus logs sejam diferentes
        // o expoente procurado será o inteiro entre ambos os números.
        // log2( n * pow(10,i) ) == log2(n) + log2( pow(10,i) ) == log2(n) + i*log2(10);
        //
        // Sempre haverá resposta, pois, para qualquer intervalo aberto contido em [0,1] existe algum
        // elemento do conjunto ( i*log2(10) )%1 já que log2(10) é irracional.

        double log2_10 = log2(10);
        double log2_n = log2(n);
        double log2_n1 = log2(n+1);

        i = 1+digitos(n);

        while ( (ULI)(log2_n + i*log2_10)  ==  (ULI)(log2_n1 + i*log2_10) )
            i++;

        cout << (ULI)(log2_n1 + i*log2_10) << endl;
    }

    return 0;
}
