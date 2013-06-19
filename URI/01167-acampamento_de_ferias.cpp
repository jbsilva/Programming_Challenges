// ============================================================================
//
//       Filename:  01167-acampamento_de_ferias.cpp
//
//    Description:  URI 1167 - Acampamento de Férias
//
//                  É um Josephus com intervalo variável.
//
//        Version:  1.0
//        Created:  17/Jun/2013 19:34:32
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <string>
#include <vector>
using namespace std;


struct crianca
{
    string nome;
    int num;

    crianca(string nome, int num): nome(nome), num(num) {}
};


int main()
{
    vector<crianca> c;
    char nome[31];
    int num;
    int N;
    while (scanf("%d", &N) && N)
    {
        for (int i = 0; i < N; i++)
        {
            scanf("%s %d", nome, &num);
            c.push_back(crianca(string(nome), num));
        }
        int idx = 0, k = c[0].num;
        while (N > 1)
        {
            if (k % 2)
                idx = (idx + k) % N;
            else
            {
                idx = (idx - (k % N)) % N;
                if (idx < 0)
                    idx = N + idx;
            }
            k = c[idx].num;
            c.erase(c.begin() + idx);
            if (k % 2)
                idx--;
            N--;
        }
        printf("Vencedor(a): %s\n", c[0].nome.c_str());
        c.clear();
    }
    return 0;
}

