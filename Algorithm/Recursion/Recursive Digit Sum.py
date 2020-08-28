n, k = map(int, input().split())
x = n * k % 9
print(x if x else 9)
