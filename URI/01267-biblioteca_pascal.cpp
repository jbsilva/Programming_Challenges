// ============================================================================
// 
//       Filename:  01267-biblioteca_pascal.cpp
// 
//    Description:  URI 1267 - Biblioteca Pascal
//                  ACM/ICPC South America Contest 2005
// 
//        Version:  1.0
//        Created:  12/Nov/2012 20:10:49
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>


int main()
{
    int alunos, jantas, foi, i, j;
    int a[101], *ptr;

    while (scanf("%d %d", &alunos, &jantas) && (alunos || jantas))
    {
        // Preenche com valores iniciais
        for (i = 0; i < alunos; i++)
        {
            scanf("%d", &foi);
            a[i] = foi;
        }

        for (j = 1; j < jantas; j++)
            for (i = 0; i < alunos; i++)
            {
                scanf("%d", &foi);
                a[i] &= foi;
            }

        a[alunos] = -1;
        ptr = a;
        bool tem = false;

        while (*ptr != -1)
        {
            if (*ptr)
            {
                tem = true; break;
            }

            ptr++;
        }

        puts(tem ? "yes" : "no");
    }

    return 0;
}
