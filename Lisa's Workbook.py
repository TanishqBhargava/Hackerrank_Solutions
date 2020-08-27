from math import ceil

def workbook(n, k, arr):
    p,c = 1,0
    for i in arr:
        for j in range(ceil(i/k)):
            if p>j*k and p<=j*k+min(k,i):
                c+=1
            i-=k
            p+=1
    return c

n,k = map(int,input().split())
arr = map(int,input().split())
print(workbook(n, k, arr))
