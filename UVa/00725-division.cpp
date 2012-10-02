// ============================================================================
// 
//       Filename:  00725-division.cpp
// 
//    Description:  UVa 725 - Division
//                  n2=abcde / n1=fghij = razao
// 
//        Version:  1.0
//        Created:  10/02/2012 10:01:18 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>

bool tem_dig[10];

inline bool valido(int n)
{
    // Tem 5 dígitos?
    if (n < 1234 || n > 98765)
        return false;

    // Repete dígito?
    for (int i=0; i < 5; i++)
    {
        int dig = n % 10;
        n /= 10;

        if (!tem_dig[dig])
            tem_dig[dig] = true;
        else
            return false;
    }

    return true;
}


int main()
{
    int n1, n2, razao;
    int caso = 0;

    while (scanf("%d", &razao) && razao != 0)
    {
        if (caso++)
            putchar('\n');

        bool tem_sol = false;
        for (n1 = 1234; n1 <= 98765; n1++)
        {
            // Verifica se repete digito
            memset(tem_dig, 0, sizeof(tem_dig));

            if (valido(n1))
            {
                n2 = n1 * razao;

                if (valido(n2))
                {
                    printf("%05d / %05d = %d\n", n2, n1, razao);
                    tem_sol = true;
                }
            }
        }
        if (!tem_sol)
            printf("There are no solutions for %d.\n", razao);
    }

    return 0;
}
