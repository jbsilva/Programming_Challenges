#!/usr/bin/env python2
# -*-*- encoding: utf-8 -*-*-
# Created: Sun, 12 May 2013 07:34:07 -0300
"""
Code Jam Round 1C 2013 - Problem A: Consonants
"""
__author__ = "Julio Batista Silva"
__copyright__ = ""
__license__ = "GPL"
__version__ = "1.0"

import fileinput

def solve(t, a):

def main():
    lines = iter(fileinput.input())
    next(lines)
    caso = 0
    for line in lines:
        caso += 1
        s, n = line.split()
        nvalue = solve(s, n)
        print "Case #{}: {}".format(caso, nvalue)

if __name__ == "__main__":
    main()
