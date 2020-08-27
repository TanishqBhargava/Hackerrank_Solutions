def chocolateFeast(n, c, m):
    count = n//c
    x = count
    while x>=m:
        a,b = divmod(x,m)
        count+=a
        x = a+b
    return count

for _ in range(int(input())):
    n,c,m = map(int,input().split())
    print(chocolateFeast(n, c, m))
