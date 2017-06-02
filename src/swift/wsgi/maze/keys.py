import os
import random


PASSWORD_FILE = os.path.join(os.path.dirname(__file__), '.passwords')


def load_keys(n):
    # TODO caching
    with open(PASSWORD_FILE) as f:
        keys = [line.split()[0] for line in f]
    return keys[n::3]


def get_key(n):
    return random.choice(load_keys(n))


def check_key(n, key):
    return key in load_keys(n)
