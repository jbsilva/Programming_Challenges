// ============================================================================
//
//       Filename:  01195-arvore_binaria_de_busca.cpp
//
//    Description:  URI 1195 - Árvore Binária de Busca
//                  
//                  Usei parte do código do UVa 536
//
//        Version:  1.0
//        Created:  21/May/2013 12:36:20
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
    int x;
    node* esq;
    node* dir;

    node(int x) : x(x), esq(NULL), dir(NULL) {}
};


void insert(int x, node* n)
{
    if (x < n->x)
    {
        if (n->esq == NULL)
        {
            node* novo = new node(x);
            n->esq = novo;
        }
        else
            insert(x, n->esq);
    }
    else
    {
        if (n->dir == NULL)
        {
            node* novo = new node(x);
            n->dir = novo;
        }
        else
            insert(x, n->dir);
    }
}


// Imprime árvore em prefixo
void preorder(node* no)
{
    if (no == NULL) return;
    printf(" %d", no->x);
    preorder(no->esq);
    preorder(no->dir);
}


// Imprime árvore em infixo
void inorder(node* no)
{
    if (no == NULL) return;
    inorder(no->esq);
    printf(" %d", no->x);
    inorder(no->dir);
}


// Imprime árvore em posfixo
void postorder(node* no)
{
    if (no == NULL) return;
    postorder(no->esq);
    postorder(no->dir);
    printf(" %d", no->x);
}


int main()
{
    int c, n, el;
    scanf("%d", &c);

    for (int caso = 1; caso <= c; caso++)
    {
        scanf("%d %d", &n, &el);
        node* raiz = new node(el);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &el);
            insert(el, raiz);
        }

        printf("Case %d:\n", caso);
        printf("Pre.:"); preorder(raiz); putchar('\n');
        printf("In..:"); inorder(raiz); putchar('\n');
        printf("Post:"); postorder(raiz); puts("\n");
    }

    return 0;
}

