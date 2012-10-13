// ============================================================================
// 
//       Filename:  1244-sort_by_length.cpp
// 
//    Description:  URI 1244 - Sort by Length
// 
//        Version:  1.0
//        Created:  13/Oct/2012 00:51:19
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


inline int comp_len(const string a, const string b)
{
    return a.length() > b.length();
}


int main()
{
    int n;
    char word[51], c;
    vector<string> palavras;
    vector<string>::iterator it;

    scanf("%d", &n);
    getchar(); //'\n'

    while (n--)
    {
        c = 0;
        while (c != '\n' && scanf("%s", word) != EOF)
        {
            palavras.push_back(string(word));
            c = getchar();
        }

        stable_sort(palavras.begin(), palavras.end(), comp_len);

        it = palavras.begin();
        cout << *it;
        for (it++; it != palavras.end(); it++)
            cout << " " << *it;
        putchar('\n');

        palavras.clear();
    }

    return 0;
}
