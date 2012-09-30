// ============================================================================
// 
//       Filename:  01160-crescimento_populacional.cpp
// 
//    Description:  URI 1160 - Crescimento Populacional
// 
//        Version:  1.0
//        Created:  09/30/2012 12:35:23 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
// 
// ============================================================================
#include <cstdio>

int main()
{
    int p1, p2;
    double g1, g2;

    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d %d %lf %lf", &p1, &p2, &g1, &g2);
        g1 = 1+g1/100;
        g2 = 1+g2/100;

        bool passou = false;
        int i;
        for (i=1; i<=100; i++)
        {
            p1 *= g1;
            p2 *= g2;

            if (p1 > p2)
            {
                passou = true;
                break;
            }
        }

        if (passou)
            printf("%d anos.\n", i);
        else
            printf("Mais de 1 seculo.\n");
    }

    return 0;
}
