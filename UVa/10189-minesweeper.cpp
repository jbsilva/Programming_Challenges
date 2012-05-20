// =====================================================================================
// 
//       Filename:  10189-minesweeper.cpp
// 
//    Description:  10189
//                  O único erro da versão 1.0 era emitir um "endl" extra logo no início
// 
//        Version:  2.0
//        Created:  03/17/2011 11:29:39 PM
//       Revision:  14/04/2011 by Julio
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <cstdlib>
#include <iostream>
#include <new>
using namespace std;

typedef unsigned short int USI;
typedef unsigned int UI;

int main()
{
    USI n, m;
    USI i, j;
    UI num_do_campo=0;
    UI contador;
    char **campo;


    // =====================================================================================
    //                          Armazena campos em uma matriz 
    // =====================================================================================
    
    cin >> n >> m;                                  // Lê a 1a linha e pega o tamanho do campo
    
    while (n != 0)
    {
        num_do_campo++;

        campo = new char*[n];
        for ( i=0; i<n; i++)
            campo[i] = new char[m];                 // Aloca a matriz do campo

        for ( i=0; i<n; i++)
        {
            for ( j=0; j<m; j++)
                cin >> campo[i][j];
        }

        // =====================================================================================
        //                          Verifica os quadrados adjacentes
        // =====================================================================================

        cout << "Field #" << num_do_campo << ":" << endl;

            for (i=0; i<n; i++)
            {
                for (j=0; j<m; j++)
                {
                    if (campo[i][j] == '*')
                        cout << "*";
                    else
                    {
                        contador = 0;

                        // Noroeste
                        if (i-1 >=0 && j-1 >=0)
                            if (campo[i-1][j-1] == '*') contador++;

                        // Norte
                        if (i-1 >=0)
                            if (campo[i-1][j] == '*') contador++;
                        
                        // Nordeste
                        if ( i-1 >= 0 && j+1 < m)
                            if (campo[i-1][j+1] == '*') contador++;

                        // Oeste
                        if (j-1 >= 0)
                            if (campo[i][j-1] == '*') contador++;

                        // Leste
                        if (j+1 < m)
                            if (campo[i][j+1] == '*') contador++;

                        // Sudoeste
                        if ( (i+1 < n) && (j-1 >= 0) )
                            if (campo[i+1][j-1] == '*') contador++;
                        
                        // Sul
                        if (i+1 < n)
                            if (campo[i+1][j] == '*') contador++;

                        // Sudeste
                        if ( (i+1 < n) && (j+1 < m) )
                            if (campo[i+1][j+1] == '*') contador++;

                        cout << contador;
                    }
                }

                cout << endl;
            }

        cin >> n >> m;                              // Lê as dimensões do próximo campo

        if (n != 0)
            cout << endl;

        delete[] campo;

    }

    return 0;
}
