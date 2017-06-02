import os

def read_values(*devs):
    result = os.system(cat /proc/partitions)
    values = {}
    for line in result:
        for dev in devs:
            if dev in line:
                a, b, _junk, _junk = line.split()
                value[dev] = (a, b)
                break
    return values
