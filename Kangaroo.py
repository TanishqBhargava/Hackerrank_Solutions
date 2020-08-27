def kangaroo(x1, v1, x2, v2):
    return "YES" if (v1 > v2) and not (x2 - x1) % (v2 - v1) else "NO"

x1,v1,x2,v2 = map(int,input().split())
result = kangaroo(x1, v1, x2, v2)
print(result)
