#!/usr/bin/env python3
# -*-*- encoding: utf-8 -*-*-
# Created: Wed, 12 Apr 2017 14:34:25 -0300

"""
URI 1763 - Santa's Translator
"""

import sys

__author__ = "Julio Batista Silva"
__copyright__ = "Copyright (c) 2017, Julio Batista Silva"
__license__ = "GPL v3"
__version__ = "1.0"
__email__ = "julio@juliobs.com"

merry_christmas = {
        'brasil':              "Feliz Natal!",
        'alemanha':            "Frohliche Weihnachten!",
        'austria':             "Frohe Weihnacht!",
        'coreia':              "Chuk Sung Tan!",
        'espanha':             "Feliz Navidad!",
        'grecia':              "Kala Christougena!",
        'estados-unidos':      "Merry Christmas!",
        'inglaterra':          "Merry Christmas!",
        'australia':           "Merry Christmas!",
        'portugal':            "Feliz Natal!",
        'suecia':              "God Jul!",
        'turquia':             "Mutlu Noeller",
        'argentina':           "Feliz Navidad!",
        'chile':               "Feliz Navidad!",
        'mexico':              "Feliz Navidad!",
        'antardida':           "Merry Christmas!",
        'canada':              "Merry Christmas!",
        'irlanda':             "Nollaig Shona Dhuit!",
        'belgica':             "Zalig Kerstfeest!",
        'italia':              "Buon Natale!",
        'libia':               "Buon Natale!",
        'siria':               "Milad Mubarak!",
        'marrocos':            "Milad Mubarak!",
        'japao':               "Merii Kurisumasu!"}

for line in sys.stdin:
    print("{}".format(merry_christmas.get(line.rstrip(), "--- NOT FOUND ---")))
