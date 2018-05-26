#!/bin/python

import math
import os
import random
import re
import sys


# Complete the fibonacciModified function below.
def fibonacciModified(t1, t2, n):
    fib = [t1, t2]
    for index in range(2, n):
        fib.append(fib[index - 2] + fib[index - 1] ** 2)

    return fib[-1]


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t1T2n = raw_input().split()

    t1 = int(t1T2n[0])

    t2 = int(t1T2n[1])

    n = int(t1T2n[2])

    result = fibonacciModified(t1, t2, n)

    fptr.write(str(result) + '\n')

    fptr.close()
