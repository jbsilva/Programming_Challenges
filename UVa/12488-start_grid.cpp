// ============================================================================
// 
//       Filename:  12488-start_grid.cpp (UVa)
//                  01228-grid_de_largada.cpp (URI)
// 
//    Description:  UVa 12488 - Start Grid
//                  URI 1228 - Grid de Largada
//                  Primeira fase da Maratona de Programação 2012
//                  Parecido com o "Bolhas e Baldes" de 2008.
//                  (SPOJ BR 3241 = UVa 11495 = URI 1088)
// 
//        Version:  1.0
//        Created:  08/Dec/2012 22:14:36
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <map>

#define INF 0x3f3f3f3f
int largada[25], ultrap;
std::map<int, int> chegada; // Guarda a posição de chegada dos carros


inline void merge(int low, int mid, int high)
{
    int n1 = mid - low + 1;       // qtd de elementos da 1a metade
    int n2 = high - mid;          // qtd de elementos da 2a metade
    int left[n1+1], right[n2+1];  // Arrays auxiliares. O +1 é para o sentinela

    // left <- largada[low..mid]; right <- largada[mid+1..right]
    for (int i=0; i < n1; i++)
        left[i] = largada[low+i];
    for (int j=0; j < n2; j++)
        right[j] = largada[mid+1+j];

    // Sentinelas
    left[n1] = INF;
    right[n2] = INF;

    int i = 0, j = 0;
    for (int k = low; k <= high; k++)
        if (chegada[left[i]] <= chegada[right[j]])
            largada[k] = left[i++];
        else
        {
            ultrap += ((mid+1) - (low+i));
            largada[k] = right[j++];
        }
}


void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid+1, high);
        merge(low, mid, high);
    }
}


int main()
{
    int comp, carro; // Número de competidores

    while (scanf("%d", &comp) != EOF)
    {
        for (int i = 0; i < comp; i++)
            scanf("%d", &largada[i]);

        for (int i = 0; i < comp; i++)
        {
            scanf("%d", &carro);
            chegada[carro] = i;
        }

        chegada[INF] = INF; // Importante para o merge_sort
        ultrap = 0;
        merge_sort(0, comp-1);

        printf("%d\n", ultrap);
        chegada.clear();
    }

    return 0;
}
