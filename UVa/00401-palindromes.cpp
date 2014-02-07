// ============================================================================
//
//       Filename:  00401-palindromes.cpp
//
//    Description:  UVa 401 - Palindromes
//
//        Version:  1.0
//        Created:  06/Feb/2014 22:40:55
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio Batista Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;


map<char, char> m;


template <class BidirectionalIterator, class OutputIterator>
bool espelha_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
{
    while (first != last)
    {
        if (m[*last] == '?')
            return false;
        --last;
        *result = m[*last];
        ++result;
    }
    return true;
}


int main()
{
    m['A'] = 'A';  m['H'] = 'H';  m['O'] = 'O';  m['V'] = 'V';  m['3'] = 'E';
    m['B'] = '?';  m['I'] = 'I';  m['P'] = '?';  m['W'] = 'W';  m['4'] = '?';
    m['C'] = '?';  m['J'] = 'L';  m['Q'] = '?';  m['X'] = 'X';  m['5'] = 'Z';
    m['D'] = '?';  m['K'] = '?';  m['R'] = '?';  m['Y'] = 'Y';  m['6'] = '?';
    m['E'] = '3';  m['L'] = 'J';  m['S'] = '2';  m['Z'] = '5';  m['7'] = '?';
    m['F'] = '?';  m['M'] = 'M';  m['T'] = 'T';  m['1'] = '1';  m['8'] = '8';
    m['G'] = '?';  m['N'] = '?';  m['U'] = 'U';  m['2'] = 'S';  m['9'] = '?';

    string pal, rev, esp;
    while (getline(cin, pal))
    {
        bool palindrome = false, mirrored = false;

        // Strings devem ter mesmo tamanho
        rev.resize(pal.size());
        esp.resize(pal.size());

        reverse_copy(pal.begin(), pal.end(), rev.begin());
        if (pal == rev)
            palindrome = true;
        if (espelha_copy(pal.begin(), pal.end(), esp.begin()) && pal == esp)
            mirrored = true;
        if (palindrome)
            if (mirrored)
                cout << pal << " -- is a mirrored palindrome.\n\n";
            else
                cout << pal << " -- is a regular palindrome.\n\n";
        else if (mirrored)
            cout << pal << " -- is a mirrored string.\n\n";
        else
            cout << pal << " -- is not a palindrome.\n\n";
    }
    return 0;
}

