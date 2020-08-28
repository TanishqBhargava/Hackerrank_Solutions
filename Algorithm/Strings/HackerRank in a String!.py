import re

def hackerrankInString(s):
    return "YES" if re.search(".*".join(list("hackerrank")), s) else "NO"

for _ in range(int(input())):
    print(hackerrankInString(input()))
