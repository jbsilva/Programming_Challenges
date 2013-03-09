// ============================================================================
//
//       Filename:  01277-short_attendance.cpp
//
//    Description:  URI 1277 - Short Attendance
//
//        Version:  1.0
//        Created:  26/Nov/2012 17:53:44
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int cases, students, dias, p;
    string alunos[101], presencas;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &students);
        for (int i = 0; i < students; i++)
            cin >> alunos[i];
        bool primeiro = true;
        for (int i = 0; i < students; i++)
        {
            cin >> presencas;
            int tam = (int)presencas.length();
            p = dias = 0;
            for (int j = 0; j < tam; j++)
                if (presencas.at(j) != 'M')
                {
                    if (presencas.at(j) == 'P')
                        p++;
                    dias++;
                }
            if ((double)p / dias < 0.75)
            {
                if (!primeiro) putchar(' ');
                printf("%s", alunos[i].c_str());
                primeiro = false;
            }
        }
        putchar('\n');
    }
    return 0;
}
