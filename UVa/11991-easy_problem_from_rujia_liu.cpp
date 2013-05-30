// ============================================================================
//
//       Filename:  11991-easy_problem_from_rujia_liu.cpp (UVa)
//                  01424-easy_problem_from_rujia_liu.cpp (URI)
//
//    Description:  UVa 11991 - Easy Problem from Rujia Liu?
//                  URI 1424 - Easy Problem from Rujia Liu?
//
//        Version:  2.0 -- Melhor desempenho
//        Created:  29/May/2013 20:03:37
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


typedef vector<int> vi;


int main()
{
    int n, m, k, v, qtd[1000001];
    vector<vi> ocorr;
    ocorr.resize(1000001);

    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(qtd, 0, sizeof(qtd));

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &v);

            if (!qtd[v])
                ocorr[v].clear();

            ocorr[v].push_back(i);

            qtd[v]++;
        }

        while (m--)
        {
            scanf("%d %d", &k, &v);

            if ((int)ocorr[v].size() < k)
                puts("0");
            else
                printf("%d\n", ocorr[v][k-1]);
        }
    }
    return 0;
}

