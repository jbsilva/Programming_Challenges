// ============================================================================
//
//       Filename:  01307-tudo_o_que_voce_precisa_e_amor.cpp
//
//    Description:  URI 1307 - Tudo o que você precisa é amor
//                  Maratona de Programação da SBC - ACM ICPC - 2001 - Warmup
//
//        Version:  1.0
//        Created:  15/Mar/2013 17:29:23
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


// Binário para Decimal
int bin2dec(char str[])
{
    int dec = 0;
    int tam = strlen(str);

    for (int i=tam-1, j=0; i >= 0; i--, j++)
        if (str[i] == '1')
            dec += 1 << j;

    return dec;
}


// Máximo divisor comum
int mdc(int a, int b)
{
    int resto = 1;
    while (resto != 0)
    {
        resto = a%b;
        a = b;
        b = resto;
    }

    return a;
}


int main()
{
    int casos;
    char s1[31], s2[31];

    scanf("%d ", &casos);

    for (int par = 1; par <= casos; par++)
    {
        if (mdc(bin2dec(gets(s1)), bin2dec(gets(s2))) != 1)
            printf("Pair #%d: All you need is love!\n", par);
        else
            printf("Pair #%d: Love is not all you need!\n", par);
    }

    return 0;
}

