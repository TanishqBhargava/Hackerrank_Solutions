def closestNumbers(arr):
    arr.sort()
    min_dif = abs(arr[0]-arr[1])
    ans = []
    for i in range(len(arr)-1):
        d = abs(arr[i]-arr[i+1])
        if d==min_dif:
            ans += [arr[i], arr[i+1]]
            min_dif =d
        elif d<min_dif:
            ans = [arr[i], arr[i+1]]
            min_dif =d
    return ans

input()
print(*closestNumbers(list(map(int,input().split()))))
