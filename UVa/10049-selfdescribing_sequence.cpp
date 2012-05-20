// =====================================================================================
// 
//       Filename:  10049-selfdescribing_sequence.cpp
// 
//    Description:  UVA 10049
//                  
//                  Criei um vetor que armazena as faixas em que f(n) se mantém, assim
//                  faixa[] = 1, 2, 4, 6, 9, 12, 16, 20...
//
//                  Então se quisermos f(10) teremos que encontrar, no vetor, o maior número
//                  menor ou igual a 10. Neste caso é 9, então retornamos a posição desse
//                  número + 1.
//                  9 está em faixa[4], então f(10) = 5;
//
//                  Para criar esse vetor, observamos que:
//                      faixa[0] = f(0) + 1                     = 1
//                      faixa[1] = f(1) + 1                     = 2
//                      faixa[2] = f(1) + f(2) + 1              = 4
//                      faixa[n] = f(1) + f(2) + ... + f(n) + 1 = faixa[n-1] + f(n)
//
//                  O vetor precisa ter apenas f(2,000,000,000) = 673365 posições.
// 
//        Version:  1.0
//        Created:  04/22/2011 04:28:50 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
using namespace std;

// Busca binária num vetor
int binarySearch(int vetor[], int first, int last, int key)
{
   while (first <= last)
   {
       int mid = (first + last) / 2;

       // Chave está na 2a metade
       if (key > vetor[mid])
           first = mid + 1;
       else
       {
           // Chave está na 1a metade
           if (key < vetor[mid])
               last = mid - 1;

           // Encontrou a chave no meio. Retorna a posição dele + 1
           else
               return mid + 1;
       }
   }

   // Não encontrou a chave. Retorna a posição do maior número menor que key + 1
   return first;
}

int main()
{
    int n, i, j, posicao;
    int *faixa;

    faixa = new int[673366];

    faixa[0] = 1;
    faixa[1] = 2;
    faixa[2] = 4;

    // Gera todas as faixas
    for (i=0; faixa[faixa[i]-1] < 2000000000; i++)
        for (j=faixa[i]; j<faixa[i+1]; j++)
            faixa[j] = faixa[j-1] + i + 1;

    while (cin >> n)
    {
        if (n > 0 && n <= 2000000000)
        {
            // Procura pelo maior número <= n no vetor + 1
            posicao = binarySearch(faixa,0,673365,n);
            cout << posicao << endl;
        }
    }

    delete[] faixa;

    return 0;
}
