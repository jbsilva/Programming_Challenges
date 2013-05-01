#!/usr/bin/env python2
# -*-*- encoding: utf-8 -*-*-
# Created: Sat, 27 Apr 2013 00:17:03 -0300

"""
Code Jam Round 1A 2013 - Problem A: Bullseye

No dia do Code Jam eu fiz com decimal, mas a precisão não foi suficiente.
Agora refiz com Bigfloat e funcionou.
"""
__author__ = "Julio Batista Silva"
__copyright__ = ""
__license__ = "GPL"
__version__ = "1.0"

import fileinput
from bigfloat import *

def solve(t, a):
    with precision(1000):
        return (2-a + sqrt(a*a - 4*a + 4 + 8*t)) / 4

def main():
    lines = iter(fileinput.input())
    next(lines)
    caso = 0
    for line in lines:
        caso += 1
        r, t = line.split()
        rings = int(solve(int(t), 2*int(r) + 1))
        print "Case #{}: {}".format(caso, rings)

if __name__ == "__main__":
    main()
