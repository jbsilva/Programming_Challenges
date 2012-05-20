// =====================================================================================
// 
//       Filename:  10137-the_trip.cpp
// 
//    Description:  UVA 10137
// 
//        Version:  2.0
//        Created:  03/18/2011 03:35:39 AM
//       Revision:  
//                  Versão 1.0:
//                              18/03/2011 -> Wrong Answer
//
//                  Versão 2.0:
//                              14/04/2011 -> Accepted
//                              Apenas mantive o modo de criar e armazenar o vetor "gastos"
//
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned short int USI;

int main()
{
    USI n, i;
    double* gastos;
    double media, rec, pag;

    while ( cin >> n && n != 0)
    {
        gastos = new double[n];

        media = rec = pag = 0.0;

        for (i=0; i<n; i++)
        {
            cin >> gastos[i];
            
            gastos[i] *= 100.0;                     // Passa para centavos

            media += gastos[i]/(double)n;          // Calcula o gasto médio
        }

        for (i=0; i<n; i++)
        {
            // Estudantes que gastaram mais. Valor que deve ser pago
            if(gastos[i] > media)
                pag += (int)(gastos[i] - media);
            else
            // Estudantes que gastaram menos. Valor que deve ser recebido
                rec += (int)(media - gastos[i]);
        }

        cout << "$" << fixed << setprecision(2) << (pag>rec ? pag : rec) / 100 << endl;

        delete[] gastos;
    }

    return 0;
}
