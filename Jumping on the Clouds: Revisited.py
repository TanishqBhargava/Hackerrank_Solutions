def jumpingOnClouds(c, k):
    i , s = 0 , 100
    while (i+k)%n: 
        s -= 3 if c[(i+k)%n] else 1
        i += k
    s -= 3 if c[0] else 1
    return s
n , k = map(int,input().split())
c = list(map(int,input().split()))
print(jumpingOnClouds(c, k))
