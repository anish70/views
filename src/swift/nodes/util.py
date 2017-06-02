import pickle

_node = {
    'id': None,
    'hostname': '',
    'ip': '0.0.0.0',
}

def create_new_node(**updates):
    _node.update(**updates)
    return _node


def read(path):
    # XXX pickle sux
    with open(path) as f:
        try:
            return pickle.load(f)
        except:
            return {}

def save(data, path):
    with open(path, 'w') as f:
        return pickle.dump(data, f)
