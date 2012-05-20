// =====================================================================================
// 
//       Filename:  847-multiplication_game.cpp
// 
//    Description:  UVA 847
//                  As melhores jogadas são:
//                      O 1o jogador sempre multiplica por 2 e o 2o sempre multiplica por 9
//                      O 1o jogador sempre multiplica por 9 e o 2o sempre multiplica por 2
//
//                  |   S   |   O   |   S   |   O   |   S   |   O   |   S   |   O   |   S   |
//                      2      18      36      324     648     5832   11664  104976  209952
//
//                                                      ou
//
//                  |   S   |   O   |   S   |   O   |   S   |   O   |   S   |   O   |   S   |
//                      9      18      162     324    2916     5832   52488  104976  944784
//
//                  Da para perceber o padrão,
//                      S ganha: 000001-000009
//                      O ganha: 000010-000018
//                      S ganha: 000019-000162
//                      O ganha: 000163-002916
//                      S ganha: 002917-005832
//                      O ganha: 005833-104976
//                      S ganha: 104976-944784
//                      O ganha: 944785-1889568
//
//        Version:  1.0
//        Created:  04/11/2011 02:15:47 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
using namespace std;

typedef unsigned long int ULI;

int main()
{
    ULI n;

    while(cin >> n)
    {
        while(n>18)
            n = (n+17)/18;

        cout << (n<=9 ? "Stan wins." : "Ollie wins.") << endl;
    }

    return 0;
}
