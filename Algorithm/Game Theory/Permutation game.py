from copy import copy
from collections import defaultdict

def renumber(arr):
    l=len(arr)
    old_num=sorted(arr)
    return [old_num.index(x)+1 for x in arr]

def F(arr):
    if tuple(arr) in d:
        return d[tuple(arr)]
    elif arr==sorted(arr):
        d[tuple(arr)]=0
        return d[tuple(arr)]
    else:
        ans=set()
        for x in arr:
            temp=copy(arr)
            temp.remove(x)
            temp=renumber(temp)
            ans.add(F(temp))
        result=0
        while result in ans:
            result+=1
        d[tuple(arr)]=result   
        return d[tuple(arr)]

d=defaultdict(int)
d[tuple([1])]=0
for _ in range(int(input())):
    arr_count = int(input())
    arr = list(map(int, input().rstrip().split()))
    print('Alice') if F(arr) else print('Bob')
