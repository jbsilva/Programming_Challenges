#!/usr/bin/env python3
# -*-*- encoding: utf-8 -*-*-
# Created: Wed, 12 Apr 2017 16:44:43 -0300

"""
URI 1911 - Help Girafales
"""


import sys


__author__ = "Julio Batista Silva"
__copyright__ = "Copyright (c) 2017, Julio Batista Silva"
__license__ = "GPL v3"
__version__ = "1.0"
__email__ = "julio@juliobs.com"


# Return the number of differences between two strings
def diff_strings(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    diff = 0

    if len1 < len2:
        smaller = str1
        bigger = str2
        diff += len2 - len1
    else:
        smaller = str2
        bigger = str1
        diff += len2 - len1

    for i in range(len(smaller)):
        if smaller[i] != bigger[i]:
            diff += 1

    return diff


while True:
    students = int(sys.stdin.readline().rstrip())

    if not students:
        break

    sigs = {}
    for _ in range(students):
        name, signature = sys.stdin.readline().split()
        sigs[name] = signature

    attending = int(sys.stdin.readline().rstrip())

    fakes = 0
    for _ in range(attending):
        name, signature = sys.stdin.readline().split()
        if diff_strings(signature, sigs[name]) > 1:
            fakes += 1

    print("{}".format(fakes))
