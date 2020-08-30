#!/bin/python3

import os
import sys

#
# Complete the bonetrousle function below.
#
def bonetrousle(n, k, b):
    init=b*(b+1)//2
    extra=(n-init)//b+1
    over=init+extra*b-n
    answer=list(range(1,b+1))
    answer=[i+extra-1 for i in answer[:over]]+[i+extra for i in answer[over:]]
    if answer[-1]<=k and answer[0]>=1:
        return answer
    else:
        return [-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        nkb = input().split()

        n = int(nkb[0])

        k = int(nkb[1])

        b = int(nkb[2])

        result = bonetrousle(n, k, b)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
