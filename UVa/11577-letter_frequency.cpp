// ============================================================================
//
//       Filename:  11577-letter_frequency.cpp (UVa)
//                  01255-letter_frequency.cpp (URI)
//
//    Description:  UVa 11577 - Letter Frequency
//                  URI 1255 - Letter Frequency
//
//                  Fiquei em 2o no URI, mas deu timelimit no UVa. Creio ser
//                  problema com o input do UVa
//
//        Version:  1.0
//        Created:  22/Oct/2012 20:51:52
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <cctype>

int main()
{
    int freq[26], cases;
    char c;
    scanf("%d", &cases);
    getchar();
    while (cases--)
    {
        memset(freq, 0, sizeof(freq));
        while ((c = getchar()) != '\n')
            freq[tolower(c) - 'a']++;
        int maior = 0;
        for (int i = 0; i < 26; i++)
            if (freq[i] > maior)
                maior = freq[i];
        for (int i = 0; i < 26; i++)
            if (freq[i] == maior)
                putchar(i + 'a');
        putchar('\n');
    }
    return 0;
}
