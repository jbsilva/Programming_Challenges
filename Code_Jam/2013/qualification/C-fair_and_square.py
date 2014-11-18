#!/usr/bin/env python2
# -*-*- encoding: utf-8 -*-*-
# Created: Fri, 12 Apr 2013 22:47:10 -0300

"""
Problem C - Fair and Square
Google Code Jam - Qualification Round 2013
"""
__author__ = "Julio Batista Silva"
__copyright__ = ""
__license__ = "GPL"
__version__ = "1.0"


import fileinput
from bisect import bisect_left, bisect_right


def eh_palin(x):
    if str(x) == str(x)[::-1]:
        return True
    else:
        return False


def gera_lista():
    fair_square = [1, 4, 9]
    p_impar = [1, 2]
    p_par = []

    for k in range(2, 51):
        if k % 2:

            n = 10**(k-1) + 1
            n2 = n*n
            if eh_palin(n2):
                p_impar.append(n)
                fair_square.append(n2)

            for p in p_impar:
                tam_p = len(str(p))
                if (tam_p + 2 <= k):
                    zeros = (k-2-tam_p)/2

                    n = 10**(k-1) + p * 10**(zeros+1) + 1
                    n2 = n*n
                    if eh_palin(n2):
                        p_impar.append(n)
                        fair_square.append(n2)

            zeros = (k-3)/2

            n = 2*10**(k-1) + 10**(zeros+1) + 2
            n2 = n*n
            if eh_palin(n2):
                p_impar.append(n)
                fair_square.append(n2)

            n = 2*10**(k-1) + 2
            n2 = n*n
            if eh_palin(n2):
                p_impar.append(n)
                fair_square.append(n2)

        else:
            n = 10**(k-1) + 1
            n2 = n*n
            if eh_palin(n2):
                p_par.append(n)
                fair_square.append(n2)

            for p in p_par:
                tam_p = len(str(p))
                if (tam_p + 2 <= k):
                    zeros = (k-2-tam_p)/2

                    n = 10**(k-1) + p * 10**(zeros+1) + 1
                    n2 = n*n
                    if eh_palin(n2):
                        p_par.append(n)
                        fair_square.append(n2)

            n = 2*10**(k-1) + 2
            n2 = n*n
            if eh_palin(n2):
                p_par.append(n)
                fair_square.append(n2)

    return sorted(fair_square)


def main():
    fs = gera_lista()
    lines = iter(fileinput.input())
    next(lines)
    caso = 0
    for line in lines:
        caso += 1
        A, B = line.split()
        L = bisect_left(fs, int(A))
        R = bisect_right(fs, int(B))
        print "Case #{}: {}".format(caso, R - L)


if __name__ == "__main__":
    main()
