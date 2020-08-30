n,a,b = input(),map(int, raw_input().split()),0
for i in a: b ^= i
print sum([int(i^b < i) for i in a])
