// ============================================================================
//
//       Filename:  10815-andys_first_dictionary.cpp (UVa)
//                  01215-andys_first_dictionary.cpp (URI)
//
//    Description:  UVa 10815 - Andy's first Dictionary
//                  URI 1215 - Andy's first Dictionary
//
//                  Olhar o histórico de commits para a versão com quicksort.
//                  Esta versão usando set foi mais rápida no UVa e usou menos
//                  memória.
//
//        Version:  3.0 -- Accepted 0.020 (UVa)
//        Created:  28/Feb/2013 21:01:17
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;


int main()
{
    set<string> palavras;
    set<string>::iterator it;
    char palavra[202], lin[202], *ptr;
    int qtd = -1;
    while (gets(lin) != NULL)
    {
        // Meu strtok personalizado
        int i = 0;
        bool anterior_letra = false;
        ptr = lin;
        while (*ptr != '\0')
        {
            if (('a' <= *ptr && *ptr <= 'z') || ('A' <= *ptr && *ptr <= 'Z'))
            {
                if (!anterior_letra)
                {
                    anterior_letra = true;
                    qtd++;
                    i = 0;
                }
                palavra[i++] = (*ptr < 'a') ? *ptr + 32 : *ptr;
            }
            else
            {
                if (anterior_letra)
                {
                    anterior_letra = false;
                    palavra[i] = '\0';
                    palavras.insert(string(palavra));
                }
            }
            ptr++;
        }
        // Para quando a linha terminar numa letra
        if (anterior_letra)
        {
            palavra[i] = '\0';
            palavras.insert(string(palavra));
        }
    }
    for (it = palavras.begin(); it != palavras.end(); ++it)
        puts(it->c_str());
    return 0;
}

