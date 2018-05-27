#!/bin/python

import math
import os
import random
import re
import sys


# Complete the gridChallenge function below.
def gridChallenge(grid):
    for i in range(len(grid)):
        prev = 'a'
        for j in range(len(grid)):
            if (prev > grid[j][i]):
                return "NO"
            prev = grid[j][i]

    return "YES"


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(raw_input())

    for t_itr in xrange(t):
        n = int(raw_input())

        grid = []

        for _ in xrange(n):
            grid_item = list(raw_input())
            grid_item.sort()
            grid.append(grid_item)

        result = gridChallenge(grid)

        fptr.write(result + '\n')

    fptr.close()
