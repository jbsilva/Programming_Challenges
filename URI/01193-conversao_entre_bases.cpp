// ============================================================================
//
//       Filename:  01193-conversao_entre_bases.cpp
//
//    Description:  URI 1193 - Conversão entre Bases
//
//        Version:  1.0
//        Created:  11/Oct/2012 09:16:34
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

inline unsigned int bin2dec(char str[])
{
    unsigned int dec = 0;
    unsigned int tam = strlen(str);
    for (int i = tam - 1, j = 0; i >= 0; i--, j++)
        if (str[i] == '1')
            dec += 1 << j;
    return dec;
}

inline string dec2bin(unsigned int n)
{
    string bin;
    char resto;
    while (n != 1)
    {
        if (n % 2 == 1)
            resto = '1';
        else
            resto = '0';
        bin.push_back(resto);
        n /= 2;
    }
    bin.push_back('1');
    reverse(bin.begin(), bin.end());
    return bin;
}

int main()
{
    unsigned int cases, n;
    char str[40], base[4];
    scanf("%u", &cases);
    for (unsigned int caso = 1; caso <= cases; caso++)
    {
        printf("Case %u:\n", caso);
        scanf("%s %s", str, base);
        switch (base[0])
        {
            case 'b':
                n = bin2dec(str);
                printf("%u dec\n", n);
                printf("%x hex\n", n);
                break;
            case 'h':
                sscanf(str, "%x", &n);
                printf("%u dec\n", n);
                cout << dec2bin(n) << " bin\n";
                break;
            case 'd':
                sscanf(str, "%u", &n);
                printf("%x hex\n", n);
                cout << dec2bin(n) << " bin\n";
                break;
        }
        putchar('\n');
    }
    return 0;
}
