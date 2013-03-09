// ============================================================================
//
//       Filename:  10935-throwing_cards_away_i.cpp (UVa)
//                  01110-throwing_cards_away.cpp (URI)
//
//    Description:  UVa 10935 - Throwing Cards Away I
//                  URI 1110 - Throwing Cards Away
//
//        Version:  1.0
//        Created:  01/Nov/2012 00:47:09
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

int main()
{
    deque<int> baralho;
    int n, i;
    while (scanf("%d", &n) && n)
    {
        if (n == 1)
            puts("Discarded cards:\nRemaining card: 1");
        else
        {
            for (i = 1; i <= n; i++)
                baralho.push_back(i);
            printf("Discarded cards: %d", baralho.front());
            baralho.pop_front();
            baralho.push_back(baralho.front());
            baralho.pop_front();
            while (baralho.size() != 1)
            {
                printf(", %d", baralho.front());
                baralho.pop_front();
                baralho.push_back(baralho.front());
                baralho.pop_front();
            }
            printf("\nRemaining card: %d\n", baralho.front());
            baralho.clear();
        }
    }
    return 0;
}
