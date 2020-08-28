import re
from itertools import combinations

def alternate(s):
    m = 0
    for i in (combinations(set(s),2)):
        j = "".join(i)
        t = re.sub("[^%s]"%j, "",s)
        if len(t)>m and not re.search(r"(\w)\1", t) :
            m = len(t)
    return m
input()
print(alternate(input()))
