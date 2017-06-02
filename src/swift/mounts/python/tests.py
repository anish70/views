from mounts import solve, check_expected_actual
import sys
import unittest


class TestCase(unittest.TestCase):

    def assertEmpty(self, iterable):
        for i in iterable:
            self.fail('Expected an empty collection, got %r' % iterable)

    def assertMatches(self, expected, actual):
        fail_msg = check_expected_actual(expected, actual)
        if fail_msg:
            self.fail(fail_msg)

    def test_no_overlap(self):
        mounts = [
            ('/', 100),
            ('/var/log', 500),
            ('/srv', 500)]
        requirements = [
            ('/var/lib/data', 500),
            ('/srv/www', 300),
            ('/var/log/auth', 100)]
        expected = {
            '/': [['/var/lib/data'], -400],
            '/var/log': [['/var/log/auth'], 400],
            '/srv': [['/srv/www'], 200]
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_with_overlap(self):
        mounts = [
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
            '/srv': [['/srv/www'], 200]
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_naive_string_matching(self):
        mounts = [
            ('/', 100),
            ('/foo', 500)]
        requirements = [
            ('/foo', 300),
            ('/foo/bar', 100),
            ('/foobar', 100)]

        expected = {
            '/': [['/foobar'], 0],
            '/foo': [['/foo', '/foo/bar'], 100],
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_naive_string_matching_part_deux(self):
        mounts = [
            ('/', 100),
            ('/a/foo/b', 500)]
        requirements = [
            ('/foo', 300),
            ('/foobar', 100)]

        expected = {
            '/': [['/foo', '/foobar'], -300],
            '/a/foo/b': [[], 500],
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_funny_characters(self):
        mounts = [
            ('/', 100),
            ('/var/log', 1000),
            ('/var/l.g', 1000),
            ('/var/l../', 22)]
        requirements = [
            ('/var/lib/data', 500),
            ('/var/log/django', 200),
            ('/var/l.g/jig', 47),
            ('/var/lag/jag', 77),
            ('/var/log/auth', 100)]

        expected = {
            '/': [['/var/lib/data', '/var/lag/jag'], 100 - 500 - 77],
            '/var/log': [['/var/log/auth', '/var/log/django'], 700],
            '/var/l.g': [['/var/l.g/jig'], 1000 - 47],
            '/var/l../': [[], 22],
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_no_matches(self):
        mounts = [
            ('/', 100),
            ('/foo', 500)]
        requirements = [
            ('/fo.', 300),
            ('/foobar', 100)]

        expected = {
            '/': [['/fo.', '/foobar'], 100 - 300 - 100],
            '/foo': [[], 500],
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_string_in_matching(self):
        mounts = [
            ('/', 100),
            ('/var/log', 500)]
        requirements = [
            ('/log', 300),
            ('/var/log', 100)]

        expected = {
            '/': [['/log'], -200],
            '/var/log': [['/var/log'], 400],
        }
        self.assertMatches(expected, solve(requirements, mounts))

    def test_mixed_formats(self):
        mounts = [
            ('/', 100),
            ('/var', 200),
            ('/var/log/', 500)]
        requirements = [
            ('/log', 300),
            ('/var/', 100),
            ('/var/log', 100)]

        expected = {
            '/': [['/log'], -200],
            '/var': [['/var/'], 100],
            '/var/log/': [['/var/log'], 400],
        }
        self.assertMatches(expected, solve(requirements, mounts))

if __name__ == "__main__":
    # As a convenience, automatically prepend "TestCase." if just test names
    # are given on the command-line.
    argv = [sys.argv[0]] + ['TestCase.' + a if not (
        a.startswith('-') or a.startswith('TestCase.')) else a
        for a in sys.argv[1:]]
    unittest.main(argv=argv)
