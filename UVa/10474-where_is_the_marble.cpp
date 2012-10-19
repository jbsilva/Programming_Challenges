// ============================================================================
// 
//       Filename:  10474-where_is_the_marble.cpp (UVa)
//                  01025-where_is_the_marble.cpp (URI)
// 
//    Description:  UVa 10474 - Where is the Marble?
//                  URI 1025 - Where is the Marble?
// 
//        Version:  1.0
//        Created:  19/Oct/2012 15:48:34
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

inline int comp_int(const void* a, const void* b)
{
    // Nao vai dar overlow, pois 0 < a e b <= 10000
    return (*(int*)a - *(int*)b);
}


int main()
{
    int marbles, queries, query, m[10001];

    int caso = 1;
    while (scanf("%d %d", &marbles, &queries) && marbles && queries)
    {
        printf("CASE# %d:\n", caso++);

        for (int i = 0; i < marbles; i++)
            scanf("%d", &m[i]);

        qsort(m, marbles, sizeof(int), comp_int);

        for (int i = 0; i < queries; i++)
        {
            scanf("%d", &query);

            if (binary_search(m, m+marbles, query))
            {
                printf("%d found at %d\n",
                        query, int(lower_bound(m, m+marbles, query) - m + 1));
            }
            else
                printf("%d not found\n", query);
        }
    }

    return 0;
}
