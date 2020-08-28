from collections import Counter

def countingSort(arr):
    s = Counter(arr)
    return (s[i] for i in range(100))

n = int(input())
arr = list(map(int,input().split()))
print(*countingSort(arr))
