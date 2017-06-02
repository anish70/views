import subprocess

failed = 'GOOD'
try:
    output = subprocess.check_output('python buckets.py < input1.dat', shell=True)
    expected = """[450, 460, 470, 480, 490, 500, 510, 520, 530, 540, 6225]\n"""
    assert output == expected

    output = subprocess.check_output('python buckets.py < input2.dat', shell=True)
    expected = """[910, 839, 1120, 1014, 1126, 900, 974, 866, 1698, 1384, 10944]\n"""
    assert output == expected

    output = subprocess.check_output('python buckets.py < input3.dat', shell=True)
    expected = '''[0, 108, 0, 0, 0, 0, 0, 0, 0, 0]\n'''
    assert output == expected
except:
    failed = 'BAD'
print failed
