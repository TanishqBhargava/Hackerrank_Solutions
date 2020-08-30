from sys import stdin,stdout
from math import gcd
for _ in range(int(stdin.readline())):
    x1,y1,x2,y2 = map(int,stdin.readline().rstrip().split(' '))
    stdout.write(str(gcd(y2-y1,x2-x1)-1)+"\n")
