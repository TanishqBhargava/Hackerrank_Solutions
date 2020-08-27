#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the surfaceArea function below.
def surfaceArea(A):
    surf = 0
    for i in range(len(A)):#for list in list.
        for e in range(len(A[i])):#for element in list.
            c = A[i][e]#current cell val
            s = (c*4)+2#surface
            
            if i > 0:#side limit.
                s -= min(c,A[i-1][e])*2
            if e > 0:#upper limit.
                s -= min(c,A[i][e-1])*2
                
            surf += s
            
    return surf

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    HW = input().split()

    H = int(HW[0])

    W = int(HW[1])

    A = []

    for _ in range(H):
        A.append(list(map(int, input().rstrip().split())))

    result = surfaceArea(A)

    fptr.write(str(result) + '\n')

    fptr.close()
