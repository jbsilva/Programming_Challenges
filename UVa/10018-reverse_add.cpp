// =====================================================================================
// 
//       Filename:  10018-reverse_add.cpp
// 
//    Description:  UVA 10018
//                  Se n já for palíndromo a saída será: "0 n"
// 
//        Version:  1.0
//        Created:  04/09/2011 09:31:52 PM
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
typedef unsigned int UI;

// Retorna o número escrito de trás para frente
UI reverte(UI num, USI base=10)
{
    UI rev;
    USI ultimo;

    rev = 0;
    while (num > 0)
    {
        ultimo = num%base;
        rev = base*rev + ultimo;
        num /= base;
    }

    return rev;
}

// Verifica se um número de uma certa base é palíndromo
bool palindromo(UI num, USI base=10)
{
    return (num == reverte(num,base) ? 1 : 0);
}

int main()
{
    USI cases, count;
    UI num;

    cin >> cases;

    while (cases--)
    {
        cin >> num;

        count = 0;
        while (!palindromo(num) && count < 1000)
        {
            num += reverte(num);
            count++;
        }

        // Segundo o enunciado, todos os testes possuem resposta, portanto não verificarei
        cout << count << " " << num << endl;
    }

    return 0;
}
