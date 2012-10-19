// ============================================================================
// 
//       Filename:  11321-sort_sort_and_sort.cpp (UVa)
//                  01252-sort_sort_and_sort.cpp (URI)
// 
//    Description:  UVa 11321 - Sort! Sort!! And Sort!!! 
//                  URI 1252 - Sort! Sort!! And Sort!!! 
// 
//        Version:  1.0
//        Created:  19/Oct/2012 14:15:25
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>

int m;

inline int comp(const void* a, const void* b)
{
    int ia = *(int*)a;
    int ib = *(int*)b;

    // ordem crescente de n%m
    if (ia % m < ib % m)
        return -1;
    else if (ia % m > ib % m)
        return 1;

    bool impar_a = ia%2;
    bool impar_b = ib%2;

    // Empate entre par e impar => impar precede
    if (impar_a && !impar_b)
        return -1;
    if (!impar_a && impar_b)
        return 1;

    // Empate entre dois impares => maior precede
    // return ib - ia causaria overflow!
    if (impar_a && impar_b)
    {
        if (ia >= ib)
            return -1;
        else
            return 1;
    }
    // Empate entre dois pares => menor precede
    if (ia <= ib)
        return -1;
    else
        return 1;
}


int main()
{
    int n, v[10001];
    while (scanf("%d %d", &n, &m) && (n || m))
    {
        printf("%d %d\n", n, m);

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        qsort(v, n, sizeof(v[0]), comp);

        for (int i = 0; i < n; i++)
            printf("%d\n", v[i]);
    }

    puts("0 0");

    return 0;
}
