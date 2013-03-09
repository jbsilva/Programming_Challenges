// ============================================================================
//
//       Filename:  00299-train_swapping.cpp (UVa)
//                  01162-train_swapping.cpp (URI)
//
//    Description:  UVa 299 - Train Swapping
//                  URI 1162 - Train Swapping
//                  É o mesmo problema do SPOJ BR 3241, mas com limite menor.
//
//        Version:  1.0
//        Created:  10/Oct/2012 22:12:07
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>

#define INF 0x3f3f3f3f
int a[52];
int trocas;


void merge(int low, int mid, int high)
{
    int n1 = mid - low + 1;       // qtd de elementos da 1a metade
    int n2 = high - mid;          // qtd de elementos da 2a metade
    int left[n1 + 1], right[n2 + 1]; // Arrays auxiliares. O +1 é para o sentinela
    // left <- a[low..mid]; right <- a[mid+1..right]
    for (int i = 0; i < n1; i++)
        left[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];
    // Sentinelas
    left[n1] = INF;
    right[n2] = INF;
    int i = 0, j = 0;
    for (int k = low; k <= high; k++)
        if (left[i] <= right[j])
            a[k] = left[i++];
        else
        {
            trocas += ((mid + 1) - (low + i));
            a[k] = right[j++];
        }
}


void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}


int main()
{
    int cases, tam;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &tam);
        for (int i = 0; i < tam; i++)
            scanf("%d", &a[i]);
        trocas = 0;
        merge_sort(0, tam - 1);
        printf("Optimal train swapping takes %d swaps.\n", trocas);
    }
    return 0;
}
