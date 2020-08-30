#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the towerBreakers function below.
def towerBreakers(n, m):
    if m!=1:
        if n%2==0:
            return 2
        else:
            return 1
    else:
        return 2

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    t = int(input())
    for t_itr in range(t):
        nm = input().split()
        n = int(nm[0])
        m = int(nm[1])
        result = towerBreakers(n, m)
        fptr.write(str(result) + '\n')
    fptr.close()
