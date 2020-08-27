def hurdleRace(k, height):
    return max(0,max(height)-k)
n,k = map(int,input().split())
height = map(int,input().split())
print(hurdleRace(k, height))
