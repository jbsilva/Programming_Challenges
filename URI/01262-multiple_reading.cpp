// ============================================================================
//
//       Filename:  01262-multiple_reading.cpp
//
//    Description:  URI 1262 - Multiple Reading
//
//        Version:  1.0
//        Created:  09/Nov/2012 12:18:37
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>


int main()
{
    char str[52], *ptr;
    int procs, r, cycles; // fp = # of free processes
    while (gets(str) != NULL)
    {
        scanf("%d", &procs); getchar();
        cycles = 0;
        ptr = str;
        while (*ptr != '\0')
        {
            r = 0;
            while (*ptr == 'R')
                r++, ptr++;
            cycles += r / procs; if (r % procs) cycles++;
            while (*ptr == 'W')
                cycles++, ptr++;
        }
        printf("%d\n", cycles);
    }
    return 0;
}
