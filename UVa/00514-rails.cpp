// ============================================================================
// 
//       Filename:  00514-rails.cpp (UVa)
//                  01062-rails.cpp (URI)
// 
//    Description:  UVa 514 - Rails
//                  URI 1062 - Rails
// 
//        Version:  1.0
//        Created:  26/Oct/2012 16:13:02
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    int tam, n, top_a; // top_a = guarda o topo da pilha A de tamanho tam
    stack<int> station;
    bool yes;

    while (scanf("%d", &tam) && tam)
    {
        scanf("%d", &n);
        while (n)
        {
            top_a = 1;
            yes = true;
            for (int i = 0; i < tam; i++)
            {
                if (i)
                    scanf("%d", &n);

                if (yes)
                {
                    if (!station.empty() && station.top() == n)
                        station.pop();
                    else if (n >= top_a)
                    {
                        while (n != top_a)
                            station.push(top_a++);
                        top_a++;
                    }
                    else
                    {
                        puts("No");
                        station = stack<int>(); // clear
                        yes = false;
                    }
                }
            }

            if (yes)
                puts("Yes");

            scanf("%d", &n);
        }
        putchar('\n');
    }

    return 0;
}
