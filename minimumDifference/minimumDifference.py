#!/bin/python

import math
import os
import random
import re
import sys


# Complete the minimumAbsoluteDifference function below.
def minimumAbsoluteDifference(n, arr):
    arr.sort()
    prev = -float('inf')
    min_difference = -prev

    for elem in arr:
        difference = elem - prev
        if min_difference > difference:
            min_difference = difference
        prev = elem

    return min_difference


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    arr = map(int, raw_input().rstrip().split())

    result = minimumAbsoluteDifference(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
