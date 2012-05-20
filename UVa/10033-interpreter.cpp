// =====================================================================================
// 
//       Filename:  10033-interpreter.cpp
// 
//    Description:  UVA 10033
// 
//        Version:  1.0
//        Created:  04/14/2011 09:31:51 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <cstdlib>
using namespace std;

typedef unsigned short int USI;
typedef unsigned int UI;

int main()
{
    USI cases, temp;
    USI a, b, c;
    UI i, count, regs[10], ram[1000];
    bool halt;
    string linha;

    cin >> cases;
    cin.ignore(2);

    while (cases--)
    {
        // Inicia registradores em 000
        for (i=0; i<10; i++)
            regs[i] = 0;

        // Zera toda a RAM
        for (i=0; i<1000; i++)
            ram[i] = 0;

        // Recebe todas as posições de memória
        i = 0;
        while( getline(cin,linha) && !linha.empty() )
        {
            temp = atoi(linha.c_str());
            
            ram[i] = temp;;

            i++;
        }

        halt = false;
        count = 0;
        i = 0;

        while( !halt )
        {
            a = ram[i] / 100;
            b = ( ram[i] % 100 ) / 10;
            c = ram[i] % 10;

            switch (a)
            {
                case 1:
                        if(ram[i] == 100)
                            halt = true;
                        break;
                case 2:
                        regs[b] = c; break;
                case 3:
                        regs[b] = (regs[b]+c)%1000; break;
                case 4:
                        regs[b] = (regs[b]*c)%1000; break;
                case 5:
                        regs[b] = regs[c]; break;
                case 6:
                        regs[b] = (regs[b]+regs[c])%1000; break;
                case 7:
                        regs[b] = (regs[b]*regs[c])%1000; break;
                case 8:
                        regs[b] = ram[regs[c]]; break;
                case 9:
                        ram[regs[b]] = regs[c]; break;
                case 0:
                        if ( regs[c] != 0 )
                            i = regs[b] - 1;
                        break;
                default:
                        break;
            }

            i++;
            count++;
        }

        cout << count << endl;

        if(cases)
            cout << endl;
    }
    
    return 0;
}
