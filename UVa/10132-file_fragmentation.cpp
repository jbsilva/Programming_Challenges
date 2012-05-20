// =====================================================================================
// 
//       Filename:  10132-file_fragmentation.cpp
// 
//    Description:  UVA 10132
//
//           TODO:  Verificar casos sem resposta, embora pelo enunciado podemos assumir
//                  que sempre tem.
// 
//        Version:  1.0
//        Created:  04/01/2011 08:08:39 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio Batista Silva (351202), juliob91(at)gmail.com
//        Company:  UFSCar
// 
// =====================================================================================

#include <iostream>
#include <string>
#include <map>
using namespace std;

int qtd_de_uns (string &arquivo)
{
    unsigned int i, count=0;

    for (i=0; i<arquivo.length(); i++)
    {
        if (arquivo.at(i) == 1)
            count++;
    }

    return count;
}

int main()
{
    unsigned int cases, qtd_de_uns_total, qtd_de_uns_arquivo, qtd, soma_tamanho, tamanho, num;
    string linha, temp;
    multimap<int,string> partes;
    map<string,int> arquivos;
    pair <multimap<int,string>::iterator, multimap<int,string>::iterator> comp;
    map<string,int>::iterator original;

    cin >> cases;

    cin.ignore(2);

    while (cases--)
    {
        // Recebe todos os pedaços
        qtd_de_uns_total = qtd = soma_tamanho = 0;

        while (getline(cin, linha) && linha != "")
        {
            partes.insert(pair<int,string>(linha.length(),linha));

            qtd_de_uns_total += qtd_de_uns(linha);

            qtd++;
            soma_tamanho += linha.length();
        }

        qtd_de_uns_arquivo = (2 * qtd_de_uns_total) / qtd;
        tamanho = (2 * soma_tamanho) / qtd;

        // Coloca todas as combinações possíveis em um mapa
        for (multimap<int,string>::iterator it=partes.begin(); it != partes.end(); it++)
        {
            // Pega só partes com o tamanho complementar
            comp = partes.equal_range( tamanho - it->first );

            for(multimap<int,string>::iterator it2=comp.first; it2!=comp.second; it2++)
            {
                temp = it->second + it2->second;

                if ( qtd_de_uns(temp) == qtd_de_uns_arquivo )
                {
                    num = arquivos[temp] + 1;
                    arquivos.erase(temp);
                    arquivos[temp] = num;
                }
            }
        }

        // A string que aparece mais vezes no mapa é a que procuramos ou não tem solucão
        original = arquivos.begin();
        for (map<string,int>::iterator it=arquivos.begin(); it != arquivos.end(); it++)
        {
            if ( it->second > original->second )
                original = it; 
        }

        cout << original->first << endl;
       
       if (cases != 0)
          cout <<  endl;
        
        partes.clear();
        arquivos.clear();
    }

    return 0;
}
