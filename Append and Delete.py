c = 0
s = input()
t = input()
k = int(input())
l = len(s)
while s[:l]!=t[:l]:
    l-=1
    c+=1
o = ((len(t)-l)+c)
if k<o:
    print("No")
elif (len(s)+len(t))<=k:
    print("Yes")
elif 2*len(t)<k:
    print("Yes")
elif k%2 == o%2:
    print("Yes")
else:
    print("No")
