#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):
    apple2 = list(apples)
    orange2 = list(oranges)

    count_apple =0
    count_orange =0
    for i in apple2:
        if s <= (a+i)<=t:
            count_apple +=1

    for j in orange2:
        if s <= (b+j) <= t:
            count_orange +=1
    print(count_apple)
    print(count_orange)


if __name__ == '__main__':
    st = input().split()
    s = int(st[0])
    t = int(st[1])
    ab = input().split()
    a = int(ab[0])
    b = int(ab[1])
    mn = input().split()
    m = int(mn[0])
    n = int(mn[1])
    apples = list(map(int, input().rstrip().split()))
    oranges = list(map(int, input().rstrip().split()))
    countApplesAndOranges(s, t, a, b, apples, oranges)
