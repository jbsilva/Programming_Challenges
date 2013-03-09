// ============================================================================
//
//       Filename:  01202-festival_das_noites_brancas.cpp
//
//    Description:  URI 1202 - Festival das Noites Brancas
//                  Problema A: Festival das noites brancas
//                  Seletiva IME-USP
//
//        Version:  1.0
//        Created:  08/18/2012 02:03:49 PM (WA)
//       Revision:  10/05/2012 12:05:00 PM (AC)
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

typedef short int SI;
typedef struct
{
    SI m[2][2];
} M2x2;

// Multiplica matrizes 2x2: a*b = c
M2x2 m_mul(M2x2 a, M2x2 b)
{
    M2x2 c;
    c.m[0][0] = (a.m[0][0] * b.m[0][0] + a.m[0][1] * b.m[1][0]) % 1000;
    c.m[0][1] = (a.m[0][0] * b.m[0][1] + a.m[0][1] * b.m[1][1]) % 1000;
    c.m[1][0] = (a.m[1][0] * b.m[0][0] + a.m[1][1] * b.m[1][0]) % 1000;
    c.m[1][1] = (a.m[1][0] * b.m[0][1] + a.m[1][1] * b.m[1][1]) % 1000;
    return c;
}


// Eleva matriz a ao quadrado e atribui a b. b = a^2
void m_sqr(M2x2 a, M2x2& b)
{
    b.m[0][0] = (a.m[0][0] * a.m[0][0] + a.m[0][1] * a.m[1][0]) % 1000;
    b.m[0][1] = (a.m[0][0] * a.m[0][1] + a.m[0][1] * a.m[1][1]) % 1000;
    b.m[1][0] = (a.m[1][0] * a.m[0][0] + a.m[1][1] * a.m[1][0]) % 1000;
    b.m[1][1] = (a.m[1][0] * a.m[0][1] + a.m[1][1] * a.m[1][1]) % 1000;
}

int main()
{
    M2x2 pot[10002]; // pot[i] = a^(2n^i)
    M2x2 resp; // resposta
    // Calcula as potências 1, 2, 4, 8, 16...2^10000 de pot
    pot[0].m[0][0] = 1; pot[0].m[0][1] = 1;
    pot[0].m[1][0] = 1; pot[0].m[1][1] = 0;
    for (int i = 1; i <= 10000; i++)
        m_sqr(pot[i - 1], pot[i]);
    char bin[10002]; int tam; // string do número binario e seu tamanho
    int cases;
    scanf("%d", &cases);
    getchar(); // \n
    while (cases--)
    {
        gets(bin);
        tam = strlen(bin);
        // Identidade
        resp.m[0][0] = 1; resp.m[0][1] = 0;
        resp.m[1][0] = 0; resp.m[1][1] = 1;
        for (int i = tam - 1, j = 0; i >= 0; i--, j++)
            if (bin[i] == '1')
                resp = m_mul(resp, pot[j]);
        printf("%03d\n", resp.m[0][1]);
    }
    return 0;
}
