
import sys

class NumericalSum(object):
    def call(self, group):
        total = 0 
        for i in range(0, len(group)):
            total += group[i]
        return total

class HistogramReport(object):
    def __init__(self, operation):
        self.operation = operation

    def group_and_process_by_last_digit(self, numbers):
        array = []
        
        array1 = []
        for i in numbers:
            if i < 100:
                array1 += [i]

        digit_groups = [] 

        for i in range(0,10):
            digit_groups += [[]]

        for i in array1:
            last = ("%d" % i)[-1]
            digit_groups[int(last)] += [i]

        for i in range(0,10):
            result = self.operation.call(digit_groups[i])
            array += [result]

        array2 = []
        for i in numbers:
            if i >= 100:
                array2 += [i]

        if len(array2) > 0:
            result = self.operation.call(array2)
            array += [result]

        return array


numbers = []
for line in sys.stdin.readlines():
    for s in line.split():
        numbers += [int(s)]

report = HistogramReport(NumericalSum()).group_and_process_by_last_digit(numbers)
print(report)
    
            

