// ============================================================================
// 
//       Filename:  01254-tag_replacement.cpp
// 
//    Description:  URI 1254 - Tag Replacement
// 
//        Version:  1.0
//        Created:  01/Nov/2012 08:07:38
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;


// Índices do '<' e do '>'
struct delim
{
    int abre;
    int fecha;

    delim(int a, int f) : abre(a), fecha(f) {}
};


int main()
{
    string tag, tag_lo, str, str_lo;
    int num, abre, fecha, i, tag_ini;
    vector<delim> delimits;
    vector<delim>::iterator it;

    while (getline(cin, tag))
    {
        cin >> num;
        cin.ignore(50, '\n');
        getline(cin, str);

        // Aloca espaço
        tag_lo.resize(tag.size());
        str_lo.resize(str.size());

        transform(tag.begin(), tag.end(), tag_lo.begin(), ::tolower);
        transform(str.begin(), str.end(), str_lo.begin(), ::tolower);

        fecha = -1;
        while ( (abre = str_lo.find('<', fecha+1)) != -1 )
        {
            fecha = str_lo.find('>', abre+1);
            delimits.push_back(delim(abre, fecha));
        }

        // Enquanto encontrar a tag
        i = 0;
        while ( (tag_ini = str_lo.find(tag_lo, i)) != -1 )
        {
            // Imprime a string antes da tag
            for (; i < tag_ini; i++)
                putchar(str.at(i));

            // tag estava entre "<>" ? imprime num : imprime tag
            // TODO: otimizar esse loop
            bool eh_tag = false;
            for (it = delimits.begin(); it != delimits.end(); it++)
                if (tag_ini > it->abre && tag_ini < it->fecha)
                {
                    eh_tag = true;
                    i += tag.length(); // avança índice para depois da tag
                    cout << num;
                    break;
                }
            if (!eh_tag)
                for (int fim = i + tag.length(); i < fim; i++)
                    putchar(str.at(i));
        }

        // Imprime o restante da string
        for (; i < (int)str.length(); i++)
            putchar(str.at(i));
        putchar('\n');

        // Apaga vetor
        delimits.clear();
    }

    return 0;
}
