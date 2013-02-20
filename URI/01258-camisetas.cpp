// ============================================================================
// 
//       Filename:  01258-camisetas.cpp
// 
//    Description:  URI 1258 - Camisetas
// 
//        Version:  1.0
//        Created:  20/Feb/2013 17:12:05
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct aluno
{
    char cor;  // b = branco, v = vermelho
    char tam; // G, M, P
    char nome[256];
};


inline int compara_aluno(const void* a, const void* b)
{
    if (((aluno*)a)->cor < ((aluno*)b)->cor)
        return -1;

    if (((aluno*)a)->cor > ((aluno*)b)->cor)
        return 1;

    if (((aluno*)a)->tam > ((aluno*)b)->tam)
        return -1;

    if (((aluno*)a)->tam < ((aluno*)b)->tam)
        return 1;

    return strcmp(((aluno*)a)->nome, ((aluno*)b)->nome);
}


int main()
{
    aluno alunos[61];
    int N;
    bool quebra_linha = false;
    while (scanf("%d ", &N) && N)
    {
        if (quebra_linha) putchar('\n');
        quebra_linha = true;

        for (int i = 0; i < N; i++)
        {
            gets(alunos[i].nome);
            scanf("%c%*s %c ", &alunos[i].cor, &alunos[i].tam);
        }

        qsort(alunos, N, sizeof(aluno), compara_aluno);

        for (int i = 0; i < N; i++)
        {
            printf(alunos[i].cor == 'b' ? "branco " : "vermelho ");
            printf("%c %s\n", alunos[i].tam, alunos[i].nome);
        }
    }

    return 0;
}

