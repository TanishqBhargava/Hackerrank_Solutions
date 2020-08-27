input()
s = list(map(int,input().split()))
d,m = map(int,input().split())
c =0
for i in range(len(s)-m+1):
    if sum(s[i:i+m])==d:
        c+=1
print(c)
