for _ in range(int(input())):
    x = int(input())
    x = x-x%5+5 if x%5>2 and x>=38 else x
    print(x)
