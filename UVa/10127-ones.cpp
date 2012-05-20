// =====================================================================================
// 
//       Filename:  10127-ones.cpp
// 
//    Description:  UVA 10127
//                  De início o problema parece complicado, mas após uma análise do
//                  funcionamento da divisão ele se torna bem simples.
//
//                  -> Armamos o método da chave colocando vários 1s no dividendo e n
//                  no divisor. Ex.: 11111 / 3
//
//                  11111 |_3_
//
//                  -> Tentamos pegar o primeiro 1 e dividir por 3. Da 0 e resto 1.
//                  11111 |_3_
//                  1   0
//
//                  -> "Abaixamos" o próximo 1 à direita do resto, que é equivalente a 1+resto*10
//                  11111 |_3_
//                  11  0
//
//                  -> Tentamos dividir 11 por 3. Da 3 resto 2, abaixamos o outro 1 ao lado do resto
//                  11111 |_3_
//                  11  03
//                   2
// 
//                  -> "Abaixamos" o próximo 1 e dividimos por 3. Da 7 resto 0
//                  11111 |_3_
//                  11  037
//                   21
//                    0
//                  
//                  -> O resto deu 0, então 111 é o primeiro múltiplo de 3 na forma 11...1
//                     Não abaixamos os próximos 1s, pois só queremos o menor múltiplo nessa forma
//
//        Version:  1.0
//        Created:  04/11/2011 12:35:15 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
using namespace std;

typedef unsigned short int USI;

int main()
{
    USI n, i, count;

    while (cin >> n)
    {
        i = count = 0;

        do
        {
            i = (i*10 + 1)% n;
            count++;
        }
        while (i);

        cout << count << endl;
    }

    return 0;
}
