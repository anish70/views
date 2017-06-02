from collections import defaultdict
from itertools import repeat
import json
import os
import re
import sys


def r(s):
    for i in range(len(s)):
        i += 1
        yield s[-i]

def d(l):
    return dict(zip(iter(l), repeat(0)))

def e(a):
    return (i for i in a if i % 2)


def m(f):
    f.data = {}
    def wrapper(*args):
        try:
            rv = f.data[args]
        except KeyError:
            rv = f.data[args] = f(*args)
        return rv
    return wrapper


def t(pred, iterator):
    for x in iterator:
        if pred(x):
            yield x
        else: 
            break

def f(l):
    for i in l:
        if isinstance(i, collections.Iterable) and not isinstance(i, basestring):
            f(i)
        else:
            yield i
