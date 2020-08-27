input()
n = list(map(int, input().split()))
b,w = n[0],n[0]
x,y = 0,0
for i in n:
    if i>b:
        b=i
        x+=1
    if i<w:
        w=i
        y+=1
print(x,y)
