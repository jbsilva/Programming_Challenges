// ============================================================================
//
//       Filename:  10035_primary_arithmetic.cpp (UVa)
//                  01212_primary_arithmetic.cpp (URI)
//
//    Description:  UVa 10035 - Primary Arithmetic
//                  URI 1212 - Primary Arithmetic
//
//        Version:  1.0
//        Created:  10/02/2012 12:57:03 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    char a[22], b[22];
    while (scanf("%s %s", a + 10, b + 10) && (a[10] != '0' || b[10] != '0'))
    {
        // Reserva os 10 primeiros caracteres para carry
        for (int i = 0; i < 10; i++)
            a[i] = b[i] = '0';
        int t_a = strlen(a);
        int t_b = strlen(b);
        int maior = (t_a > t_b ? t_a : t_b) - 10;
        int carry = 0;
        for (int i = 1; i <= maior; i++)
            if (a[t_a - i] - '0' + b[t_b - i] - '0' > 9)
            {
                carry++;
                a[t_a - i - 1] += 1;
            }
        if (carry == 1)
            puts("1 carry operation.");
        else if (carry > 1)
            printf("%d carry operations.\n", carry);
        else
            puts("No carry operation.");
    }
    return 0;
}
