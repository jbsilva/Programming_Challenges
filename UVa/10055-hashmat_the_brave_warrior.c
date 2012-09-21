/*
 * =====================================================================================
 *
 *       Filename:  10055-hashmat_the_brave_warrior.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2012 10:16:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Julio B. Silva (351202), julio(at)juliobs.com
 *   Organization:  UFSCar
 *
 * =====================================================================================
 */
#include <stdio.h>

int main()
{
    long long int n1, n2;
    while (scanf("%lld %lld", &n1, &n2) != EOF)
        printf("%lld\n", (n1>n2 ? n1-n2 : n2-n1));

    return 0;
}
