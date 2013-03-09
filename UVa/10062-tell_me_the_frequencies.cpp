// ============================================================================
//
//       Filename:  10062-tell_me_the_frequencies.cpp (UVa)
//                  01251-tell_me_the_frequencies.cpp (URI)
//
//    Description:  UVa 10062 - Tell me the frequencies!
//                  URI 1251 - Tell me the frequencies!
//
//        Version:  1.0
//        Created:  14/Oct/2012 02:48:20
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct
{
    int freq;
    int ascii;
} caract;

inline int comp_freq(const void* a, const void* b)
{
    caract ca = *(caract*)a;
    caract cb = *(caract*)b;
    if (ca.freq < cb.freq)
        return -1;
    if (ca.freq > cb.freq)
        return 1;
    if (ca.ascii > cb.ascii)
        return -1;
    else
        return 1;
}

int main()
{
    int tam, i;
    caract chars[128];
    char line[1001];
    bool primeiro = true;
    while (gets(line) != NULL)
    {
        if (!primeiro)
            putchar('\n');
        primeiro = false;
        tam = strlen(line);
        memset(chars, 0, sizeof(chars));
        for (i = 0; i < tam; i++)
        {
            chars[(int)line[i]].freq++;
            chars[(int)line[i]].ascii = (int)line[i];
        }
        qsort(chars, 128, sizeof(chars[0]), comp_freq);
        i = 0;
        while (!chars[i].freq)
            i++;
        for (; i < 128; i++)
            printf("%d %d\n", chars[i].ascii, chars[i].freq);
    }
    return 0;
}
