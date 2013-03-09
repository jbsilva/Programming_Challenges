// ============================================================================
//
//       Filename:  10701-pre_in_and_post.cpp (UVa)
//                  01194-pre_in_and_post.cpp (URI)
//
//    Description:  UVa 10701 - Pre, in and Post
//                  URI 1194 - Pre, in and Post
//
//                  Semelhante a URI 1191 -> UVa 536, do mesmo autor.
//
//        Version:  1.0
//        Created:  16/Feb/2013 16:32:33
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

#define DESALOCA 0 // Subi um pouco no ranking sem desalocar a memória

char inord[53], preord[53];
int posicao[60]; // A -> posicao[0], z -> posicao[57]
struct node
{
    char c;
    node* esq;
    node* dir;

    node(char c) : c(c), esq(NULL), dir(NULL) {}
};

void insert(char c, node* n)
{
    if (posicao[(int)c - 'A'] < posicao[(int)n->c - 'A'])
    {
        if (n->esq == NULL)
        {
            node* novo = new node(c);
            n->esq = novo;
        }
        else
            insert(c, n->esq);
    }
    else
    {
        if (n->dir == NULL)
        {
            node* novo = new node(c);
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
    int cases, tam;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d %s %s", &tam, preord, inord);
        for (int i = 0; i < tam; i++)
            posicao[(int)inord[i] - 'A'] = i;
        node* raiz = new node(preord[0]);
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

