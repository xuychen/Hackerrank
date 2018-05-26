#!/bin/python

import math
import os
import random
import re
import sys


# Complete the marcsCakewalk function below.
def marcsCakewalk(calorie):
    calorie.sort(reverse=True)
    sum = 0

    for index in range(len(calorie)):
        cup_calorie = calorie[index]
        sum += cup_calorie * (2 ** index)

    return sum


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(raw_input())

    calorie = map(int, raw_input().rstrip().split())

    result = marcsCakewalk(calorie)

    fptr.write(str(result) + '\n')

    fptr.close()
