// ============================================================================
// 
//       Filename:  00536-tree_recovery.cpp (UVA)
//                  01191-recuperacao_da_arvore (URI)
// 
//    Description:  UVA 536 - Tree Recovery
//                  URI 1191 - Recuperação da Árvore
//
//                  Construir o percurso posfixo de uma árvore binária a partir
//                  dos percursos infixo e prefixo.
// 
//        Version:  1.0
//        Created:  05/Feb/2013 15:34:17
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstring>

#define DESALOCA 0 // Subi um pouco no ranking sem desalocar a memória

char inord[27], preord[27];
int posicao[26];
struct node
{
    char c;
    node *esq;
    node *dir;

    node(char c) : c(c), esq(NULL), dir(NULL) {}
};

void insert(char c, node* n)
{
    if (posicao[(int)c - 'A'] < posicao[(int)n->c - 'A'])
    {
        if (n->esq == NULL)
        {
            node *novo = new node(c);
            n->esq = novo;
        }
        else
            insert(c, n->esq);
    }
    else
    {
        if (n->dir == NULL)
        {
            node *novo = new node(c);
            n->dir = novo;
        }
        else
            insert(c, n->dir);
    }
}

// Imprime árvore em posfixo
void postorder(node* no)
{
    if (no == NULL) return;

    postorder(no->esq);
    postorder(no->dir);
    putchar(no->c);
}

#if DESALOCA
// Economiza memória
void desaloca(node* no)
{
    if (no != NULL)
    {
        node* esq = no->esq;
        node* dir = no->dir;
        delete no;

        desaloca(esq);
        desaloca(dir);
    }
}
#endif

int main()
{
    while (scanf("%s %s", preord, inord) != EOF)
    {
        int tam = strlen(inord);

        for (int i = 0; i < tam; i++)
            posicao[(int)inord[i] - 'A'] = i;

        node *raiz = new node(preord[0]);

        for (int i = 1; i < tam; i++)
            insert(preord[i], raiz);

        // Imprime em posfixo
        postorder(raiz);
        putchar('\n');

#if DESALOCA
        // Desnecessário para a maratona, mas evita memory leak
        desaloca(raiz);
#endif
    }

    return 0;
}

