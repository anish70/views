import os
import sys
import util

DATA_FILE = 'pickle.dat'

def get_updated_node(nodes, node_id, **updates):
    """
    get a node from nodes and update; possibly creating
    """
    try:
        node = nodes[node_id]
    except KeyError:
        nodes[node_id] = util.create_new_node(**updates)
    else:
        nodes[node_id].update(**updates)
    return nodes[node_id]

def get(args):
    '''apply args'''
    nodes = None
    try:
        updates = {}
        for update in args:
            k, v = update.split('=')
            updates[k] = v
        try:
            node_id = updates['id']
        except IndexError, KeyError:
            print 'ERROR: id= is required'
            sys.exit(1)
        nodes = util.read(DATA_FILE)
        return get_updated_node(nodes, node_id, **updates)
    finally:
        if nodes:
            util.save(nodes, DATA_FILE)

def display():
    nodes = util.read(DATA_FILE)
    for node in nodes:
        print ' '.join('='.join([k, v]) for k, v in
                       nodes[node].items())


if __name__ == "__main__":
    """
    example.py [key=value]...]]
    """
    if not sys.stdin.isatty():
        os.system(': > pickle.dat')
        for line in sys.stdin.readlines():
            get(line.split())
        sys.exit(0)
    _prog = sys.argv.pop(0)
    if not sys.argv:
        display()
    else:
        print get(sys.argv)
