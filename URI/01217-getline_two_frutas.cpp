// ============================================================================
// 
//       Filename:  01217-getline_two_frutas.cpp
// 
//    Description:  URI 1217 - Getline Two - Frutas
// 
//        Version:  1.0
//        Created:  10/06/2012 06:01:39 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

int main()
{
    double valor, gasto = 0;
    int days, kg, soma = 0;
    char c;

    scanf("%d", &days);
    for (int day=1; day <= days; day++)
    {
        scanf("%lf", &valor);
        gasto += valor;

        getchar(); // '\n'
        kg = 1;
        while ((c = getchar()) != '\n')
            if (c == ' ')
                kg++;

        soma += kg;

        printf("day %d: %d kg\n", day, kg);
    }

    printf("%.2lf kg by day\nR$ %.2lf by day\n", (double)soma/days, gasto/days);

    return 0;
}
