// ============================================================================
//
//       Filename:  12532-interval_product.cpp (UVa)
//                  01301-produto_do_intervalo.cpp (URI)
//
//    Description:  ACM/ICPC South America Contest 2012.
//                  UVa 12532 - Interval Product
//                  URI 1301 - Produto do Intervalo
//
//                  Criei uma segment tree dinâmica com base no livro
//                  Competitive Programming 2ed.
//
//                  -----------------------------------------------------------
//                                            [1]=0[1,4]                      |
//                                   /                         \              |
//                               [2]=-[1,2]                [3]=0[3,4]         |
//                             /            \            /            \       |
//                         [4]=-[1,1]   [5]=+[2,2]   [6]=0[3,3]   [7]=-[4,4]  |
//                  seq[]:    -2            6            0           -1       |
//                  Idx:       1            2            3            4       |
//
//        Version:  3.0
//        Created:  09/Feb/2013 01:34:43
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <vector>
using namespace std;

int elems, seq[100001];
int st[262144]; // Segment Tree: Heap de tam 2*2^(floor(log2(10^5))+1) = 262144


void st_build(int vertex, int L, int R)
{
    if (L == R)
        st[vertex] = (seq[L] > 0) - (seq[L] < 0); // retorna -1, 0 ou 1
    else
    {
        int nL = 2 * vertex, nR = 2 * vertex + 1;
        int m = (L + R) / 2;
        st_build(nL, L  , m);
        st_build(nR, m + 1, R);
        st[vertex] = st[nL] * st[nR];
    }
}


int st_query(int vertex, int L, int R, int i, int j)
{
    // Segmento [i,j] fora do intervalo [L,R].
    // Retorna 1, pois 1 é o elemento neutro da multiplicação
    if (i > R || j < L) return 1;
    if (i <= L && j >= R) return st[vertex]; // Segmento [i,j] contém [L,R]
    int m = (L + R) / 2;
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    int p1 = st_query(nL, L  , m, i, j);
    int p2 = st_query(nR, m + 1, R, i, j);
    return p1 * p2;
}


// seq[index] = val e atualiza a árvore de segmentos
void st_update(int vertex, int L, int R, int index, int val)
{
    if (L == R) // L e R = index
    {
        seq[index] = val;
        st[vertex] = (seq[L] > 0) - (seq[L] < 0); // retorna -1, 0 ou 1
    }
    else
    {
        int m = (L + R) / 2;
        int nL = 2 * vertex, nR = 2 * vertex + 1;
        if (index <= m)
            st_update(nL, L    , m, index, val);
        else
            st_update(nR, m + 1, R, index, val);
        st[vertex] = st[nL] * st[nR];
    }
}


int main()
{
    int rodadas, n1, n2;
    while (scanf("%d %d", &elems, &rodadas) != EOF)
    {
        for (int i = 1; i <= elems; i++)
            scanf("%d ", &seq[i]);
        st_build(1, 1, elems);
        char c;
        while (rodadas--)
        {
            scanf("%c %d %d ", &c, &n1, &n2);
            if (c == 'C')
            {
                seq[n1] = n2;
                st_update(1, 1, elems, n1, n2);
            }
            else
            {
                int resp = st_query(1, 1, elems, n1, n2);
                if (!resp)
                    putchar('0');
                else if (resp < 0)
                    putchar('-');
                else
                    putchar('+');
            }
        }
        putchar('\n');
    }
    return 0;
}
