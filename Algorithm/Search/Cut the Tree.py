import sys
import copy
n = int(raw_input())
point = [int(x) for x in raw_input().split(' ')]
sp = sum(point)

v = set([])
mi = float('inf')
def dfs(p):
    global mi
    v.add(p)
    r = point[p - 1]
    for k in table[p]:
        if k in v:
            continue
        s = dfs(k)
        mi = min(mi, abs(sp - s - s))
        r += s
    return r

def nr_dfs(p):
    global mi
    sta = [p]
    while len(sta) > 0:
        t = sta[-1]
        if len(donetable[t]) == 0:
            r = point[t - 1]
            for k in table[t]:
                #print k, t
                if t not in pre or k != pre[t]:
                    r += valuetable[k]
            mi = min(mi, abs(sp - r - r))
            valuetable[t] = r
            sta.pop()

        for k in donetable[t]:
                pre[k] = t
                sta.append(k)
                donetable[k].remove(t)
        donetable[t] = set([])



table = {}
for i in range(n - 1):
    [p, q] = [int(x) for x in raw_input().split(' ')]
    if p in table:
        table[p].add(q)
    else:
        table[p] = set([q])
    if q in table:
        table[q].add(p)
    else:
        table[q] = set([p])

donetable = copy.deepcopy(table)
valuetable = {}
pre = {}
nr_dfs(1)
print mi
