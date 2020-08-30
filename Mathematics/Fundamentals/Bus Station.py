#!/bin/python3

import os
import sys

# Complete the solve function below.
def solve(groups):
    total = sum(groups)
    viables = {}  # bus size : people on current (unfilled) bus
    cum_sum = 0
    for group in groups:
    # try putting group in each of the viable branches
        for size, current_bus in list(viables.items()):
            current_bus += group
      # if overfull, bus size no longer viable
            if current_bus > size:
                viables.pop(size)
                continue
    # if bus is full, bring in a new one
            if current_bus == size:
                current_bus = 0
            viables[size] = current_bus
        cum_sum += group  # running sum of all groups so far
        if total % cum_sum == 0:  # if running sum divides total, 
            viables[cum_sum] = 0  # it's a new viable bus size
    return list(viables)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a_count = int(input())

    a = list(map(int, input().rstrip().split()))

    result = solve(a)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
