// ============================================================================
// 
//       Filename:  01248-diet_plan.cpp
// 
//    Description:  URI 1248 - Diet Plan
// 
//        Version:  1.0
//        Created:  12/Oct/2012 14:48:13
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    set<char> diet;
    set<char>::iterator it;
    char c;
    int cases;

    scanf("%d", &cases);
    getchar(); //'\n'
    while (cases--)
    {
        // Diet
        diet.clear();
        while ((c = getchar()) != '\n')
            diet.insert(c);

        bool cheater = false;

        // Breakfast
        while ((c = getchar()) != '\n')
            if (!diet.erase(c))
                cheater = true;

        // Lunch
        while ((c = getchar()) != '\n')
            if (!diet.erase(c))
                cheater = true;

        if (!cheater)
        {
            for (it = diet.begin(); it != diet.end(); it++)
                putchar(*it);
            putchar('\n');
        }
        else
            puts("CHEATER");
    }

    return 0;
}
