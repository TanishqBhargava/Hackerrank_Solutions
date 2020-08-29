#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the cipher function below.
def cipher(k, s):
    n = len(s)
    sz = n-k+1
    message = p = s[0]
    j = 1
    if k <= sz:
        while j < k:
            l = s[j]
            message += l if p == '0' else inv(l)
            p = l
            j += 1
        while j < sz:
            l = xor(s[j], s[j-1])
            dec_bit = message[j-k]
            message += l if dec_bit == '0' else inv(l)
            j += 1
    else:
        while j < sz:
            l = xor(s[j], s[j-1])
            message += l
            j += 1
    
    return message

def inv(l):
    return '1' if l == '0' else '0'

def xor(a,b):
    return '0' if a == '0' and b == '0' or a == '1' and b == '1' else '1'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])
    s = input()
    result = cipher(k, s)
    fptr.write(result + '\n')
    fptr.close()
