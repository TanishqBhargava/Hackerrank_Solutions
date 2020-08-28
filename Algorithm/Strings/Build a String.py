for i in range(int(input())):
    n, a, b = map(int, input().split())
    s = input()
    dp, dp[0], res = [0]*n, a, ''
    for i in range(1, n):
        res+=s[i]
        while res:
            if res in s[:i+1-len(res)]: break
            else: res = res[1:]
        if res: dp[i] = min(dp[i-1]+a, dp[i-len(res)]+b)
        else: dp[i] = dp[i-1]+a
    print(dp[-1]) 
