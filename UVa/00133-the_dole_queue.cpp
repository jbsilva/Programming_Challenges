// ============================================================================
//
//       Filename:  00133-the_dole_queue.cpp (UVa)
//                  01119-the_dole_queue.cpp (URI)
//
//    Description:  UVa 133 - The Dole Queue
//                  URI 1119 - The Dole Queue
//
//        Version:  1.0 - TLE
//        Created:  06/Feb/2013 16:06:22
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

struct node
{
    int num;
    bool ativo;
    node* esq;
    node* dir;

    node(int num, bool ativo, node* esq, node* dir) :
        num(num), ativo(ativo), esq(esq), dir(dir) {}
};


void remove(node* n)
{
    (n->esq)->dir = n->dir;
    (n->dir)->esq = n->esq;
    n->ativo = false;
    //delete n;
}


int main()
{
    int N, k, m;
    while (scanf("%d %d %d", &N, &k, &m) && (N || k || m))
    {
        // Cria lista circular
        node* primeiro = new node(1, true, NULL, NULL);
        node* anterior = primeiro;
        for (int i = 2; i <= N; i++)
        {
            node* atual = new node(i, true, anterior, NULL);
            anterior->dir = atual;
            anterior = atual;
        }
        // "anterior" aqui é o último da lista circular
        primeiro->esq = anterior;
        anterior->dir = primeiro;
        // Simulação
        bool por_virgula = false;
        node* p1 = primeiro;
        node* p2 = anterior;
        while (42)
        {
            for (int i = 1; i < k; i++)
                p1 = p1->dir;
            for (int i = 1; i < m; i++)
                p2 = p2->esq;
            if (por_virgula)
                putchar(',');
            if (p1 != p2)
            {
                printf("%3d%3d", p1->num, p2->num);
                remove(p1); remove(p2);
                N -= 2;
            }
            else
            {
                printf("%3d", p1->num);
                remove(p1);
                N--;
            }
            if (N == 0)
            {
                putchar('\n');
                break;
            }
            // Avança p1 e p2 para próxima posição disponível
            while (!p1->ativo) p1 = p1->dir;
            while (!p2->ativo) p2 = p2->esq;
            por_virgula = true;
        }
    }
    return 0;
}

