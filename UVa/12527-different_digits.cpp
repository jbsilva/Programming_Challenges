// ============================================================================
// 
//       Filename:  12527-different_digits.cpp
// 
//    Description:  UVa 12527 - Different Digits
//                  
//                  Final Brasileira da Maratona de Programação 2012
// 
//        Version:  1.0
//        Created:  11/Nov/2012 20:55:10
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>


inline bool repete(int n)
{
    bool dig[10];
    memset(dig, 0, sizeof(dig));

    while (n)
    {
        if (dig[n%10])
            return true;

        dig[n%10] = 1;
        n /= 10;
    }

    return false;
}


int main()
{
    int n, m, i, resp;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        resp = 0;
        for (i = n; i <= m; i++)
            if (!repete(i))
                resp++;

        printf("%d\n", resp);
    }

    return 0;
}
