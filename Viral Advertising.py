a = 5
b = 0
for i in range(1,int(input())+1):
    b += a//2
    a  = a//2*3
print(b)
