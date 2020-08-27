from collections import Counter
def equalizeArray(arr):
    return len(arr) - max(Counter(arr).values())
input()
arr = list(map(int,input().split()))
print(equalizeArray(arr))
