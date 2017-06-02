from collections import defaultdict
import json
import os
import re
import sys


def z(l):
    return list(set(l))

def h(r, g, b):
    return '%x%x%x' % (r, g, b)

TRUE_VALUES = set(('true', '1', 'yes', 'on', 't', 'y'))
def c(v):
    return v is True or (isinstance(v, basestring) and v.lower() in TRUE_VALUES)

def ex():
    for l in sys.stdin.readlines():
        if not re.match('\s*#', l): 
            sys.stdout.write(l)

def g(items):
    g = defaultdict(list)
    for i in items:
        g[i['type']].append(i)
    return g


