// ============================================================================
// 
//       Filename:  00136-ugly_numbers.cpp
// 
//    Description:  136 - Ugly Numbers
// 
//        Version:  1.0
//        Created:  09/23/2012 05:29:56 PM
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
#if 0
    int count = 1;
    int i=1;
    while (count != 1500)
    {
        i++;
        int n = i;
        while (n%2 == 0)
            n /= 2;
        while (n%3 == 0)
            n /= 3;
        while (n%5 == 0)
            n /= 5;

        if (n == 1) 
            count++;
    }

    printf("The 1500'th ugly number is %d.\n", i);
#else
    puts("The 1500'th ugly number is 859963392.");
#endif

    return 0;
}
