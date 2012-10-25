// ============================================================================
// 
//       Filename:  01256-tabelas_hash.cpp
// 
//    Description:  URI 1256 - Tabelas Hash
// 
//        Version:  1.0
//        Created:  24/Oct/2012 23:18:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int cases, tam, chaves, chave;
    vector<int> hash[100];
    vector<int>::iterator it;

    scanf("%d", &cases);
    for (int caso=0; caso < cases; caso++)
    {
        scanf("%d %d", &tam, &chaves);
        
        for (int i = 0; i < chaves; i++)
        {
            scanf("%d", &chave);
            hash[chave%tam].push_back(chave);
        }

        if (caso) putchar('\n');
        for (int i = 0; i < tam; i++)
        {
            printf("%d -> ", i);
            for (it = hash[i].begin(); it != hash[i].end(); it++)
                printf("%d -> ", *it);
            puts("\\");

            hash[i].clear();
        }
    }

    return 0;
}
