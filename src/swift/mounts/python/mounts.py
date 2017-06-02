from copy import deepcopy
from pprint import pformat
import sys


def check_expected_actual(expected, actual):
    expected_c = deepcopy(expected)
    actual_c = deepcopy(actual)
    fail_msgs = []
    for mount, (paths, space) in expected_c.items():
        if mount in actual_c:
            actual_paths, actual_space = actual_c.pop(mount)
            for path in paths:
                if path in actual_paths:
                    actual_paths.remove(path)
                else:
                    fail_msgs.append(
                        'Path %r missing in list for key %r' % (
                            path, mount))
            if actual_paths:
                fail_msgs.append(
                    'Extra path(s) %r in list for key %r' % (
                        actual_paths, mount))
            if space != actual_space:
                fail_msgs.append(
                    'Expected %r MB for key %r but got %r' % (
                        space, mount, actual_space))
        else:
            fail_msgs.append(
                'Missing top-level path %r' % (mount,))
    if actual_c:
        fail_msgs.append(
            'Extra top-level path(s): %r' % (actual_c,))
    if fail_msgs:
        fail_prefix = '\nEXPECTED:\n  %s\nGOT:\n  %s\nISSUES:' % (
            pformat(expected, indent=2).replace('\n', '\n  '),
            pformat(actual, indent=2).replace('\n', '\n  '))
        return fail_prefix + ''.join(['\n  * ' + m for m in fail_msgs])
    return ''


def parse(filename):
    """
    Input: (str) name of a file to parse, containing data in this format:
              100M /
              200M /some/path
              300M /different/path
    Returns: a list of (path, size) 2-tuples
    """
    path_sizes = []
    with open(filename) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue

            raw_size, path = line.split(None, 1)
            size = int(raw_size.rstrip('M'))
            path_sizes.append((path, size))
    return path_sizes


def solve(requirements, available):
    '''
    requirements is a list of the form [(directory, required_bytes),],
    where directory is a string of the form '/a/b/c' representing a directory
    and required_bytes is an integer

    available has the same structure, but instead of a directory this should be
    interpreted as a mount point (and its available capacity remaining).

    solve should return a dictionary where the keys are the mount points
    and the values are lists of the form:
        [[list of directories], remaining_space]

    List of directories is a collection of all the directories in requirements
    that will live under the given mount point, and remaining space is an
    integer, with positive representing left over space on the mount and
    a negative number representing how much space needs to be added to the
    mount to support all the requirements.

    For these example inputs,

        available = [
            ('/', 100),
            ('/var/log', 1000),
            ('/srv', 500),
        ]
        requirements = [
            ('/var/lib/data', 500),
            ('/var/log/django', 200),
            ('/srv/www', 300),
            ('/var/log/auth', 100),
        ]

    solve(available, requirements) would return:

        {
            '/': [['/var/lib/data'], -400],
            '/var/log': [['/var/log/auth', '/var/log/django'], 700],
            '/srv': [['/srv/www'], 200]
        }
    '''
    return {}


def main():
    available = [
        ('/', 100),
        ('/var/log', 1000),
        ('/srv', 500)]
    requirements = [
        ('/var/lib/data', 500),
        ('/var/log/django', 200),
        ('/srv/www', 300),
        ('/var/log/auth', 100)]

    expected = {
        '/': [['/var/lib/data'], -400],
        '/var/log': [['/var/log/auth', '/var/log/django'], 700],
        '/srv': [['/srv/www'], 200]}

    got = solve(requirements, available)
    fail_msg = check_expected_actual(expected, got)
    print fail_msg if fail_msg else 'Success!'


if __name__ == "__main__":
    sys.exit(main())
