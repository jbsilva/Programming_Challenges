#!/usr/bin/env python3
# -*-*- encoding: utf-8 -*-*-
# Created: Wed, 12 Apr 2017 15:11:04 -0300

"""
URI 2482 - Noel's Labels
"""


import sys


__author__ = "Julio Batista Silva"
__copyright__ = "Copyright (c) 2017, Julio Batista Silva"
__license__ = "GPL v3"
__version__ = "1.0"
__email__ = "julio@juliobs.com"


while True:
    N = sys.stdin.readline().rstrip()

    if not N:
        break
    else:
        N = int(N)

    translation = {}

    for _ in range(N):
        lang = sys.stdin.readline().rstrip()
        translation[lang] = sys.stdin.readline().rstrip()

    M = int(sys.stdin.readline().rstrip())

    for _ in range(M):
        name = sys.stdin.readline().rstrip()
        lang = sys.stdin.readline().rstrip()

        print("{}\n{}\n".format(name, translation[lang]))
