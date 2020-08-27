def beautifulTriplets(d, arr):
    a = set(arr)
    return len([1 for i in arr if i+d in a and i+d*2 in a])
n,d = map(int,input().split())
arr = list(map(int,input().split()))
print(beautifulTriplets(d, arr))
