import os
import subprocess
import unittest


class TestCase(unittest.TestCase):

    def setUp(self):
        os.system('python nodes.py < example.dat')

    def test_list_all_nodes(self):
        expected = [
            "ip=192.168.1.100 hostname=prod.swiftstack.com id=1",
            "ip=192.168.1.1 hostname=staging.swiftstack.com id=2",
        ]
        results = subprocess.check_output('python nodes.py', shell=True)
        for expected, result in zip(expected, results.splitlines()):
            for part in expected.split():
                self.assert_(part in result)

    def test_list_single_node(self):
        expected = [
            "{'ip': '192.168.1.100', 'hostname': 'prod.swiftstack.com', 'id': '1'}",
        ]
        results = subprocess.check_output('python nodes.py id=1', shell=True)
        for expected, result in zip(expected, results.splitlines()):
            self.assertEqual(expected, result)

    def test_update_a_node(self):
        expected = [
            "{'ip': '72.55.189.57', 'hostname': 'prod.swiftstack.com', 'id': '1'}",
        ]
        results = subprocess.check_output('python nodes.py id=1 ip=72.55.189.57', shell=True)
        for expected, result in zip(expected, results.splitlines()):
            self.assertEqual(expected, result)

    def test_add_a_node(self):
        expected = [
            "{'ip': '0.0.0.0', 'hostname': 'demo.swiftstack.com', 'id': '3'}",
        ]
        results = subprocess.check_output('python nodes.py id=3 hostname=demo.swiftstack.com', shell=True)
        for expected, result in zip(expected, results.splitlines()):
            self.assertEqual(expected, result)


if __name__ == "__main__":
    unittest.main()
