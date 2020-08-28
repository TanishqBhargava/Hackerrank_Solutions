from collections import Counter

def anagram(s):
    if len(s)%2: return -1
    l = len(s)//2
    a = Counter(s[:l])
    b = Counter(s[l:])
    return l-sum((a & b).values())

for _ in range(int(input())):
    print(anagram(input()))
