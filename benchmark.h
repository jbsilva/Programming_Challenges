/*
 * ============================================================================
 *
 *       Filename:  benchmark.h
 *
 *    Description:  Função para medir o tempo de execução de trechos do código.
 *                  Compile com -lrt no gcc
 *
 *            Uso:
 *                  timespec t1, t2;
 *                  clock_gettime(CLOCK_REALTIME, &t1);
 *                  clock_gettime(CLOCK_REALTIME, &t2);
 *                  printf("%ld:%ld\n", diff(t1,t2).tv_sec, diff(t1,t2).tv_nsec);
 *
 *        Version:  1.0
 *        Created:  18/Oct/2012 20:01:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Julio B. Silva (351202), julio(at)juliobs.com
 *   Organization:  UFSCar
 *
 * ============================================================================
 */
#include <ctime>
timespec diff(timespec start, timespec end)
{
	timespec temp;
	if (end.tv_nsec - start.tv_nsec < 0)
    {
		temp.tv_sec = end.tv_sec - start.tv_sec - 1;
		temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
	}
    else
    {
		temp.tv_sec = end.tv_sec - start.tv_sec;
		temp.tv_nsec = end.tv_nsec - start.tv_nsec;
	}
	return temp;
}
