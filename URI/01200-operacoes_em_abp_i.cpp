// ============================================================================
//
//       Filename:  01200-operacoes_em_abp_i.cpp
//
//    Description:  URI 1200 - Operações em ABP I
//
//                  Parte do código baseado em URI 1194 e URI 1195
//
//        Version:  1.0
//        Created:  02/Jul/2013 18:42:41
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>


#define DESALOCA 0 // Desnecessário para a maratona, mas evita memory leak


bool primeiro = true;


struct node
{
    char c;
    node* esq;
    node* dir;
    node(char c) : c(c), esq(NULL), dir(NULL) {}
};


void insert(char c, node* n)
{
    if (c < n->c)
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


void pesquisa(char c, node* n)
{
    if (n == NULL)
        printf("%c nao existe\n", c);
    else if (c == n->c)
        printf("%c existe\n", c);
    else if (c < n->c)
        pesquisa(c, n->esq);
    else
        pesquisa(c, n->dir);
}


// Imprime árvore em prefixo
void preorder(node* no)
{
    if (no == NULL) return;
    if (primeiro)
        {primeiro = false; putchar(no->c);}
    else
        printf(" %c", no->c);
    preorder(no->esq);
    preorder(no->dir);
}


// Imprime árvore em infixo
void inorder(node* no)
{
    if (no == NULL) return;
    inorder(no->esq);
    if (primeiro)
        {primeiro = false; putchar(no->c);}
    else
        printf(" %c", no->c);
    inorder(no->dir);
}


// Imprime árvore em posfixo
void postorder(node* no)
{
    if (no == NULL) return;
    postorder(no->esq);
    postorder(no->dir);
    if (primeiro)
        {primeiro = false; putchar(no->c);}
    else
        printf(" %c", no->c);
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
    char lin[100];
    // Lê e insere o primeiro elemento
    gets(lin);
    node* raiz = new node(lin[2]);

    while (gets(lin) != NULL)
    {
        switch (lin[1])
        {
            case ' ':
                lin[0] == 'I' ? insert(lin[2], raiz) : pesquisa(lin[2], raiz);
                break;
            case 'N':
                primeiro = true; inorder(raiz); putchar('\n'); break;
            case 'R':
                primeiro = true; preorder(raiz); putchar('\n'); break;
            case 'O':
                primeiro = true; postorder(raiz); putchar('\n');
        }

        #if DESALOCA
        desaloca(raiz);
        #endif
    }
    return 0;
}

