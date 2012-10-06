// ============================================================================
// 
//       Filename:  10473-simple_base_conversion.cpp (UVa)
//                  01199-simple_base_conversion.cpp (URI)
//
//    Description:  UVa 10473 - Simple Base Conversion
//                  URI 1199 - Simple Base Conversion
// 
//        Version:  1.0
//        Created:  10/05/2012 11:02:58 PM
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
    int n;
    char str[12];
    while (scanf("%s", str) != EOF)
    {
        if (str[0] != '-')
        {
            sscanf(str, "%i", &n);
            if (str[1] == 'x') // hex
                printf("%d\n", n);
            else
                printf("0x%X\n", n);
        }
    }

    return 0;
}
