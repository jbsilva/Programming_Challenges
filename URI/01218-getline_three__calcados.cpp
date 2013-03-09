// ============================================================================
//
//       Filename:  01218-getline_three__calcados.cpp
//
//    Description:  URI 1218 - Getline Three - Calçados
//
//
//        Version:  1.0
//        Created:  07/Oct/2012 16:51:31
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

int main()
{
    int mas[25], fem[25]; // mas[0] = qtd de calçados masculinos tamanho 20
    int num, offset;
    char line[1001], sex;
    int n, caso = 0;
    while (scanf("%d ", &n) != EOF)
    {
        memset(mas, 0, sizeof(mas));
        memset(fem, 0, sizeof(fem));
        gets(line);
        char* l = line;
        // O '%n' do sscanf retorna o número de caracteres consumidos.
        while (sscanf(l, "%d %c%n", &num, &sex, &offset) != EOF)
        {
            l += offset; // incrementa ponteiro
            if (sex == 'M')
                mas[num - 20]++;
            else
                fem[num - 20]++;
        }
        if (caso++) putchar('\n'); // Não imprime no primeiro caso
        printf("Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n",
               caso, mas[n - 20] + fem[n - 20], fem[n - 20], mas[n - 20]);
    }
    return 0;
}
