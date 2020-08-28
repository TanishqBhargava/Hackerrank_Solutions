def palindromeIndex(s):
    for i,j in enumerate(range(0,len(s)//2),1):
        if s[-i] == s[j]:
            continue
        if s[j:-i]==s[j:-i][::-1]:
            return len(s)-i
        elif s[j+1:-i+1]==s[j+1:-i+1][::-1]:
            return j
        return -1
    return -1

for _ in range(int(input())):
    print(palindromeIndex(input()))
