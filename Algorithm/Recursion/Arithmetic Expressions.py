#!/bin/python3

import sys

S = ('+', lambda x, y: x + y)
D = ('-', lambda x, y: x - y + 101)
M = ('*', lambda x, y: x * y)
func = [S, D, M]

def arithmeticExpressions(arr):
    form, index = _ae(arr)
    remain = len(arr) - index
    extra = zip(['*'] * remain, arr[-remain:])
    extra_s = ''.join([o + str(n) for o, n in extra])
    return form + extra_s

def _ae(arr):
    cache = {}
    first = arr[0]
    cache[first] = str(first)
    for index, n in enumerate(arr[1:]):
        next_cache = {}
        for val in cache:
            for name, f in func:
                next_val = f(val, n) % 101
                next_form = cache[val] + name + str(n)
                if next_val == 0:
                    return next_form, index + 2
                next_cache[next_val] = next_form
        cache = next_cache

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split(' ')))
    result = arithmeticExpressions(arr)
    print(result)
