// ============================================================================
//
//       Filename:  12241-digits_count.cpp (UVa)
//                  01138-digits_count.cpp (URI)
//
//    Description:  UVa 12241 - Digits Count
//                  URI 1138 - Digits Count
//
//                  http://math.stackexchange.com/questions/47477 ajudou muito.
//                  Semelhante à 1a parte da solução do Project Euler 156, mas
//                  aqui também precisamos considerar as ocorrências do 0.
//
//        Version:  1.0
//        Created:  15/Oct/2012 20:12:27
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


// pow10[i] = 10^i
int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

// dig[i][0] -> qtd de dígitos i (0-9) até a (não inclusive)
// dig[i][1] -> qtd de dígitos i (0-9) até b (inclusive)
int dig[10][2];

// Preenche vetor d com digitos de 1 ate n (inclusive)
inline void d_ate_n(int n, bool a_ou_b)
{
    int k = 0; // 0 = casa das unidades, 1 = casa das dezenas ...
    int ap;
    int calda = 0;
    int r0 = 0;
    while (n)
    {
        // Tratamos um digito por vez
        int d = n % 10; n /= 10;
        // Cada digito aparece k*10^(k-1) vezes no intervalo [0..10^k-1]
        // E esse intervalo aparece d vezes
        if (k > 0)
        {
            ap = d * pow10[k - 1] * k;
            for (int i = 0; i < 10; i++)
                dig[i][a_ou_b] += ap;
            if (d == 0)
                r0 += pow10[k] - 1 - calda;     // remove os 0s contados a mais
        }
        // Os números até d (não inclusive) aparecem mais 10^k vezes
        ap = pow10[k];
        for (int i = 1; i < d; i++)
            dig[i][a_ou_b] += ap;
        // Soma o número a direita do dígito d, pois eles estavam faltando.
        if (d != 0)
            dig[d][a_ou_b] += calda + 1;
        calda += pow10[k] * d; // k ultimos digitos
        k++;
    }
    dig[0][a_ou_b] -= r0;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b) && (a || b))
    {
        memset(dig, 0, sizeof(dig));
        d_ate_n(a - 1, 0);
        d_ate_n(b, 1);
        printf("%d", dig[0][1] - dig[0][0]);
        for (int i = 1; i < 10; i++)
            printf(" %d", dig[i][1] - dig[i][0]);
        putchar('\n');
    }
    return 0;
}
