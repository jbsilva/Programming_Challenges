// ============================================================================
//
//       Filename:  12243-flowers_flourish_from_france.cpp (UVa)
//                  01140-flowers_flourish_from_france.cpp (URI)
//
//    Description:  UVa 12243 - Flowers Flourish from France
//                  URI 1140 - Flowers Flourish from France
//
//        Version:  1.0
//        Created:  04/Feb/2013 02:01:04
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cctype>

int main()
{
    char frase[1100], *ptr, inicial, palavra[21];
    while (gets(frase) && frase[0] != '*')
    {
        bool tautograma = true;
        int offset;
        inicial = tolower(frase[0]);
        ptr = frase;
        while (sscanf(ptr, "%s%n", palavra, &offset) != EOF)
        {
            ptr += offset;
            if (tolower(palavra[0]) != inicial)
            {
                tautograma = false;
                break;
            }
        }
        puts(tautograma ? "Y" : "N");
    }
    return 0;
}

