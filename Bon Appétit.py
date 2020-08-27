def bonAppetit(bill, k, b):
    return b-(sum(bill)//2-bill[k]//2) or "Bon Appetit"
n,k = map(int,input().split())
bill = list(map(int,input().split()))
b = int(input())
print(bonAppetit(bill, k, b))
