#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the gridlandMetro function below.
def gridlandMetro(n, m, k, track):
    track.sort()                                        #1
    out = n * m                                         #2
    r0 = t1 = t2 = 0
    for r, c1, c2 in track:                             #3
        if r == r0 and c1 - 1 < t2: t2 = max(t2, c2)    #4
        else:
            out -= t2 - t1                              #5
            r0, t1, t2 = r, c1 - 1, c2                  #6
    return(out - t2 + t1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nmk = input().split()
    n = int(nmk[0])
    m = int(nmk[1])
    k = int(nmk[2])
    track = []
    for _ in range(k):
        track.append(list(map(int, input().rstrip().split())))
    result = gridlandMetro(n, m, k, track)
    fptr.write(str(result) + '\n')
    fptr.close()
