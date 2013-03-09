// ============================================================================
//
//       Filename:  3237-apagando_e_ganhando.cpp (SPOJ BR)
//                  01084-apagando_e_ganhando.cpp (URI)
//
//    Description:  SPOJ BR 3237- Apagando e Ganhando
//                  URI 1084 - Apagando e Ganhando
//                  Primeira fase da Maratona de Programação - 2008
//
//                  br.spoj.pl/problems/APAGA/
//
//        Version:  1.0
//        Created:  03/Nov/2012 22:24:03
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <deque>
using namespace std;

// O(n)
int main()
{
    deque<char> digs;
    deque<char>::iterator it;
    int n, d, tam_final, i;
    char num[100002];
    while (scanf("%d %d ", &n, &d) && n)
    {
        tam_final = n - d;
        gets(num);
        for (i = 0; i < n; i++)
        {
            while (!digs.empty() && d > 0 && num[i] > digs.back())
            {
                digs.pop_back();
                d--;
            }
            if ((int)digs.size() < tam_final)
                digs.push_back(num[i]);
        }
        for (it = digs.begin(); it != digs.end(); it++)
            putchar(*it);
        putchar('\n');
        digs.clear();
    }
    return 0;
}

// N^2
/*
int main()
{
    int n, d, i, j, removidos;
    char num[100002], maior;
    while (scanf("%d %d ", &n, &d) && n)
    {
        gets(num);
        for (j = 0; j < n-d; j += removidos+1)
        {
            maior = '0';
            removidos = 0;
            for (i = j; i <= d+j; i++)
                if (num[i] > maior)
                {
                    maior = num[i];
                    removidos = i-j;
                }
            d -= removidos;
            putchar(maior);
        }
        putchar('\n');
    }
    return 0;
}
*/
