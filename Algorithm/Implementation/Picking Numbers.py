from collections import Counter
def pickingNumbers(a):
    a = Counter(a)
    maxi = 0
    for k in sorted(a):
        m = a[k]+a.get(k+1,0)
        if maxi<m:
            maxi=m
    return maxi
input()
a = map(int,input().split())
print(pickingNumbers(a))
