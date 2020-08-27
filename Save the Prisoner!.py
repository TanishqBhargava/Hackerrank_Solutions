def saveThePrisoner(n, m, s):
    return (m%n+s-1)%n or n

for _ in range(int(input())):
    n,m,s = map(int,input().split())
    print(saveThePrisoner(n, m, s))
