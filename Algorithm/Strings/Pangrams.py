def pangrams(s):
    s = set(s)
    s.discard(" ")
    return "pangram" if len(s)==26 else "not pangram"
print(pangrams(input().lower()))
