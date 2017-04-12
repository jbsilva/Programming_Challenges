#!/usr/bin/env python
# -*-*- encoding: utf-8 -*-*-
# Created: Thu, 23 Mar 2017 14:43:49 -0300

"""
URI 1704 - Arranging Tasks
"""

__author__ = "Julio Batista Silva"
__copyright__ = "Copyright (c) 2017, Julio Batista Silva"
__license__ = "GPL v3"
__version__ = "1.0"
__email__ = "julio@juliobs.com"


import sys
from operator import itemgetter

while True:
    line = sys.stdin.readline()
    if not line:
        break

    tasks_count, hours = map(int, line.split())

    tasks = []

    total_value = 0
    for i in range(tasks_count):
        v, t = map(int, sys.stdin.readline().split())
        total_value += v
        tasks.append((v, t))

    # Sort tasks by decreasing value
    tasks.sort(key=itemgetter(0), reverse=True)

    # Simulation. Try to fit the biggest value where possible
    solution = {}
    for task in tasks:
        for i in range(task[1], 0, -1):
            if i not in solution:
                solution[i] = task[0]
                break

    print("{}".format(total_value - sum(solution.values())))
