// ============================================================================
//
//       Filename:  01168-led.cpp
//
//    Description:  URI 1168 - LED
//
//        Version:  1.0
//        Created:  26/Oct/2012 15:51:30
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Julio B. Silva (351202), julio(at)juliobs.com
//        Company:  UFSCar
//
// ============================================================================
#include <cstdio>
#include <cstring>

int leds[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int cases, tam, sum;
    char num[102];
    scanf("%d", &cases);
    getchar();
    while (cases--)
    {
        gets(num);
        tam = strlen(num);
        sum = 0;
        for (int i = 0; i < tam; i++)
            sum += leds[(int)num[i] - '0'];
        printf("%d leds\n", sum);
    }
    return 0;
}
