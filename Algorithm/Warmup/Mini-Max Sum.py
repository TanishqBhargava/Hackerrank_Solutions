import sys

def miniMaxSum(arr):
    # Complete this function
    arr.sort()
    tot = sum(arr)
    print((tot - arr[-1]), (tot - arr[0]))
    
if __name__ == "__main__":
    arr = list(map(int, input().strip().split(' ')))
    miniMaxSum(arr)
