num = int(input())

for _ in range(num):
    arr_num = int(input())
    arr = list(map(int, input().strip().split()))
    print("NO") if sum([1 for i in range(len(arr)) for j in range(i+1, len(arr)) if arr[i] > arr[j] ])%2 else print("YES")
