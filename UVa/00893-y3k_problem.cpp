// ============================================================================
// 
//       Filename:  00893-y3k_problem.cpp
// 
//    Description:  893 - Y3K Problem
// 
//        Version:  1.0
//        Created:  09/23/2012 07:14:23 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
using namespace std;

int days, d, m, a;

// Verifica se ano é bissexto
inline bool leap(int ano)
{
    if (ano % 400 == 0)
        return true;
    if (ano % 100 == 0)
        return false;
    if (ano % 4 == 0)
        return true;
    return false;
}

inline void inc_mes()
{
    if (m < 12)
        m++;
    else
    {
        m = 1;
        a++;
    }
}

int main()
{
    //                nil,jan,fev,mar,abr,mai,jun,jul,ago,set,out,nov,dez
    int dias_mes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (cin >> days >> d >> m >> a && (days || d || m || a))
    {
        // Incrementa anos inteiros
        while (days > 365)
        {
            // leap year
            if (days > 365 && ( (m <= 2 && leap(a)) || (m > 2 && leap(a+1)) ))
            {
                days -= 366;
                a++;
            }
            // nao leap
            else
            {
                days -= 365;
                a++;
            }
        }

        // Incrementa dia a dia. Vai rodar no maximo 365 vezes
        while (days--)
        {
            if (d < dias_mes[m])
                d++;
            else if (d == 28 && m == 2 && leap(a))
                d = 29;
            else
            {
                d = 1;
                inc_mes();
            }
        }

        cout << d << " " << m << " " << a << endl;
    }

    return 0;
}
