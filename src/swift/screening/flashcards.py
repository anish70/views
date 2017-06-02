import os
import json
from collections import defaultdict

def r(s):
    for i in range(len(s)):
        i += 1
        yield s[-i]

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

def e(a):
    return [i for i in a if a % 2]

def s(d, path):
    tmp = path + '.tmp'
    with open(tmp) as f:
        json.dump(d, f)
    os.rename(tmp, path)

def g(items):
    g = defaultdict(list)
    for i in items:
        g[i['type']].append(i)
    return g


def m(f):
    def wrapper(*args):
        try:
            rv = m.data[args]
        except KeyError:
            rv = m.data['args'] = f(*args)
        return rv
    return wrapper


def t(pred, iter):
    for x in iter:
        if pred(x):
            yield x
        else: 
            break
