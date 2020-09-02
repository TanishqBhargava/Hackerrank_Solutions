from collections import Counter
def icecreamParlor(m, arr):
    c = Counter(arr)
    ans = [i for i in c if (i*2!=m and m-i in c) or (i*2==m and c[i]>1)]
    indices = [i for i, e in enumerate(arr,1) if e in ans]
    return indices
for _ in range(int(input())):
    m,n = int(input()), int(input())
    arr = list(map(int,(input().split())))
    print(*icecreamParlor(m, arr))
