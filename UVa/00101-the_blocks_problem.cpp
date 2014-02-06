// ============================================================================
//
//       Filename:  00101-the_blocks_problem.cpp
//
//    Description:  UVa 101 - The Blocks Problem
//
//        Version:  1.0
//        Created:  06/Feb/2014 17:56:28
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


int n, a, b;
int pilha[25]; // Informa em qual pilha cada elemento está
char comando[20], cmd1[10], cmd2[10];
vector<int> table[25];
vector<int>::iterator it;


// Desempilha todos os elementos da pilha 'p' acima de 'k' (não inclusive)
void desempilha(int p, int k)
{
    for (it = table[p].begin(); it != table[p].end() && *it != k; ++it) {}
    vector<int>::iterator inicio = ++it;
    for (; it != table[p].end(); ++it)
    {
        pilha[*it] = *it;
        table[*it].push_back(*it);
    }
    table[p].erase(inicio, table[p].end());
}


void move_over(int a, int b)
{
    // Retorna elementos acima de a às suas posições originais
    desempilha(pilha[a], a);
    // move 'a' sobre pilha onde está 'b'
    table[pilha[a]].pop_back();
    table[pilha[b]].push_back(a);
    pilha[a] = pilha[b];
}


void move_onto(int a, int b)
{
    // Retorna elementos acima de 'b' às suas posições originais
    desempilha(pilha[b], b);
    // Move elemento
    move_over(a, b);
}


void pile_over(int a, int b)
{
    // pilha[a] será modificado. Precisamos guardar o valor inicial
    int pilha_a = pilha[a];
    // move 'a' e todos os elementos acima dele sobre 'b'
    for (it = table[pilha_a].begin(); it != table[pilha_a].end() && *it != a; ++it) {}
    vector<int>::iterator inicio = it;
    for (; it != table[pilha_a].end(); ++it)
    {
        table[pilha[b]].push_back(*it);
        pilha[*it] = pilha[b];
    }
    table[pilha_a].erase(inicio, table[pilha_a].end());
}


void pile_onto(int a, int b)
{
    // Retorna elementos acima de 'b' às suas posições originais
    desempilha(pilha[b], b);
    // Empilha
    pile_over(a, b);
}


void imprime()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (it = table[i].begin(); it != table[i].end(); ++it)
            printf(" %d", *it);
        putchar('\n');
    }
}


int main()
{
    scanf("%d ", &n);
    for (int i = 0; i < n; i++)
    {
        table[i].push_back(i);
        pilha[i] = i;
    }
    while (gets(comando) && strcmp(comando, "quit"))
    {
        sscanf(comando, "%s %d %s %d", cmd1, &a, cmd2, &b);
        if (pilha[a] != pilha[b])
        {
            if (cmd1[0] == 'm') // move
            {
                if (cmd2[1] == 'n') // onto
                    move_onto(a, b);
                else
                    move_over(a, b);
            }
            else // pile
            {
                if (cmd2[1] == 'n') // onto
                    pile_onto(a, b);
                else
                    pile_over(a, b);
            }
        }
    }
    // Imprime resposta
    imprime();
    return 0;
}
