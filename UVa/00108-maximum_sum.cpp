// ============================================================================
//
//       Filename:  00108-maximum_sum.cpp
//
//    Description:  UVa 108 - Maximum Sum
//
//        Version:  1.0
//        Created:  07/Jul/2013 17:32:06
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int main()
{
    int n, max = -0x3f3f3f3f, m[100][100], col[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    for (int a = 0; a < n; a++) // 1a linha
    {
        memset(col, 0, sizeof(col));
        for (int b = a; b < n; b++) // última linha
        {
            int sum = 0; // soma de valores no retângulo de (a,?) a (b, c)
            for (int c = 0; c < n; c++) // última coluna
            {
                col[c] += m[b][c];
                sum += col[c];
                if (sum > max) max = sum;
                if (sum < 0) sum = 0; // ignora colunas anteriores
            }
        }
    }
    printf("%d\n", max);
    return 0;
}

