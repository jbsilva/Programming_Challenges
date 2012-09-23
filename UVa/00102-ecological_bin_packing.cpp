// ============================================================================
// 
//       Filename:  00102-ecological_bin_packing.cpp
// 
//    Description:  102 - Ecological Bin Packing
//                  Existem apenas 6 permutações de 3 elementos.
// 
//        Version:  1.0
//        Created:  09/22/2012 10:29:14 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
using namespace std;

#define INF 0x3f3f3f3f
typedef unsigned long long int ULLI;

int main()
{
    // Usar strcpy acabou sendo mais lento que enum + array
    enum cores     { BGC,   BCG,   GBC,   GCB,   CBG,   CGB};
    string cor[] = {"BGC", "BCG", "GBC", "GCB", "CBG", "CGB", "ERRO"};

    char temp;
    while (cin >> temp)
    {
        // retorna o caractere ao buffer
        cin.unget();

        ULLI b[3][3];
        ULLI soma = 0;
        for (int i=0; i < 3; i++)
            for (int j=0; j < 3; j++)
            {
                cin >> b[i][j];
                soma += b[i][j];
            }

        ULLI min = INF;
        ULLI movs = 0;
        int ordem = 6;

        // Atenção para a ordem alfabética
        //021 = BCG
        movs = soma - b[0][0] - b[1][2] - b[2][1];
        if (movs < min) {min = movs; ordem = BCG;}

        //012 = BGC
        movs = soma - b[0][0] - b[1][1] - b[2][2];
        if (movs < min) {min = movs; ordem = BGC;}

        //201 = CBG
        movs = soma - b[0][2] - b[1][0] - b[2][1];
        if (movs < min) {min = movs; ordem = CBG;}

        //210 = CGB
        movs = soma - b[0][2] - b[1][1] - b[2][0];
        if (movs < min) {min = movs; ordem = CGB;}

        //102 = GBC
        movs = soma - b[0][1] - b[1][0] - b[2][2];
        if (movs < min) {min = movs; ordem = GBC;}

        //120 = GCB
        movs = soma - b[0][1] - b[1][2] - b[2][0];
        if (movs < min) {min = movs; ordem = GCB;}

        cout << cor[ordem] << " " << min << endl;
    }
    return 0;
}
