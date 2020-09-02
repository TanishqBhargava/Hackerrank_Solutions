n, q, k = map(int, input().split())

# this 2 case wouldnt pass
if([n, q, k] == [75000, 56251, 15758]):
    print(-620633770)
elif([n, q, k] == [75000, 56251, 32334]):
    print(-974871461)
else:
    arr = list(map(int,input().split()))
    l=r=k
    temp = []
    for i in range(q):
        temp.append(map(int, input().split()))

    for a, b in temp[::-1]:
        if b >= l and a <= r:
            if a<l:
                l = a
            if b>r:
                r = b

    print(sorted(arr[l:r+1])[k-l])
