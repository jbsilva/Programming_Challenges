// ============================================================================
// 
//       Filename:  11221-magic_square_palindromes.cpp
// 
//    Description:  UVa 11221 - Magic Square Palindromes
// 
//        Version:  1.0
//        Created:  09/26/2012 08:47:23 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <iostream>
#include <cstdio>

// Quadrados perfeitos
int sqrs[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225,
    256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676, 729, 784, 841, 900,
    961, 1024, 1089, 1156, 1225, 1296, 1369, 1444, 1521, 1600, 1681, 1764,
    1849, 1936, 2025, 2116, 2209, 2304, 2401, 2500, 2601, 2704, 2809, 2916,
    3025, 3136, 3249, 3364, 3481, 3600, 3721, 3844, 3969, 4096, 4225, 4356,
    4489, 4624, 4761, 4900, 5041, 5184, 5329, 5476, 5625, 5776, 5929, 6084,
    6241, 6400, 6561, 6724, 6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100,
    8281, 8464, 8649, 8836, 9025, 9216, 9409, 9604, 9801, 10000};


inline int busca_binaria(int *v, int n, int x)
{
    int min, max, meio;

    min = 0;
    max = n;
    do
    {
        meio = (min + max) / 2;
        if (x > v[meio])
            min = meio + 1;
        else
            max = meio - 1;
    } while(v[meio] != x && (min <= max));

    if (v[meio] == x)
        return meio;

    return -1;
}


int main()
{
    char t[10001], ch;

    int cases, k;
    scanf("%d ", &cases);
    for (int caso=1; caso <= cases; caso++)
    {
        printf("Case #%d:\n", caso);

        // kxk é o número de caracteres. No final será = k*k
        int kxk = 0;
        while ((ch = getchar()) != '\n')
            if (ch >= 'a' && ch <= 'z')
                t[kxk++] = ch;

        // A quantidade de caracteres deve formar um quadrado perfeito
        if ((k = busca_binaria(sqrs, 100, kxk)) != -1)
        {
            // Palindromo de tras para frente.
            for (int i=0, j=kxk-1; i < j; i++, j--)
                if (t[i] != t[j])
                    goto NO_MAGIC;

            // Palindromo por colunas
            for (int i=0, j=kxk-1; i < j; i+=k, j-=k)
                if (t[i] != t[j])
                    goto NO_MAGIC;

            printf("%d\n", k); // MAGIC!
        }
        else
            NO_MAGIC: puts("No magic :(");
    }

    return 0;
}
