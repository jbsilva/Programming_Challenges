// ============================================================================
// 
//       Filename:  10469-to_carry_or_not_to_carry.cpp (UVa)
//                  01026-to_carry_or_not_to_carry.cpp (URI)
// 
//    Description:  UVa 10469 - To Carry or not to Carry
//                  URI 1026 - To Carry or not to Carry
//
//        Version:  1.0
//        Created:  10/02/2012 06:58:25 PM
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
    unsigned long long int a, b;
    while (scanf("%llu %llu", &a, &b) != EOF)
        printf("%llu\n", a ^ b);

    return 0;
}
