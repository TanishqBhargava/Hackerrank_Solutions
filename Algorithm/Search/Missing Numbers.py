from collections import Counter
def missingNumbers(arr, brr):
    a = [x for x,y in brr.items() if y-arr.get(x,0)]
    return sorted(a)
n,arr = input(), Counter(map(int,(input().split())))
m,brr = input(), Counter(map(int,(input().split())))
print(*missingNumbers(arr, brr))
