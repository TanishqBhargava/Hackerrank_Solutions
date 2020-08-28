def gemstones(arr):
    return len(set.intersection(*arr))
arr = [set(input()) for i in range(int(input()))]
print(gemstones(arr))
