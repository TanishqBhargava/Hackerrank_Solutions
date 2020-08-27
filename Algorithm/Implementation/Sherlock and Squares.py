from math import sqrt

def squares(a, b):
    c = int(sqrt(b))-int(sqrt(a))
    return c+1 if int(sqrt(a))**2==a else c

for _ in range(int(input())):
    a,b = map(int,input().split())
    print(squares(a, b))
