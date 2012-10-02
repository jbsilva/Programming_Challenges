// ============================================================================
// 
//       Filename:  10300-ecological_premium.cpp
// 
//    Description:  UVa 10300 - Ecological Premium
// 
//        Version:  1.0
//        Created:  10/01/2012 09:21:18 PM
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
    int cases;
    scanf("%d", &cases);

    while (cases--)
    {
        int sum = 0;
        int f;
        scanf("%d", &f);
        for (int i=0; i < f; i++)
        {
            int size, animals, env;
            scanf("%d %d %d", &size, &animals, &env);
            sum += env*size;
        }

        printf("%d\n", sum);
    }

    return 0;
}
