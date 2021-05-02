#!/usr/bin/env python3
# -*-*- encoding: utf-8 -*-*-
# Created: Sun, 02 May 2021 14:08:28 -0300

"""URI 1540 - Energy Planning."""

import sys

__author__ = "Julio Batista Silva"
__copyright__ = "Copyright (c) 2021, Julio Batista Silva"
__license__ = "GPL v3"
__version__ = "1.0"
__email__ = "julio@juliobs.com"

N = int(sys.stdin.readline().rstrip())

for _ in range(N):
    y1, c1, y2, c2 = [int(x) for x in sys.stdin.readline().split()]
    rate = str(int(100*(c2-c1)/(y2-y1)))
    print(f"{rate[:-2]},{rate[-2:]}")
