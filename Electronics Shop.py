def getMoneySpent(keyboards, drives, b):
    maxval = 0
    for x in keyboards:
        for y in drives:
            s= x+y
            if s>maxval and s<=b:
                maxval= s
    return maxval or -1

b,n,m = map(int,input().split())
k  = list(map(int,input().split()))
d  = list(map(int,input().split()))
print(getMoneySpent(k, d, b))
