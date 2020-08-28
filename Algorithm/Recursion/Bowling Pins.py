g = [0, 1, 2]
for n in xrange(3, 301):
    s = set()
    # hit one or two pins
    for l in (1, 2):
        # the group of n pins can be split into two 
        # grops of i and n - l - i pins
        for i in xrange((n - l)/2 + 1):
            s.add(g[i]^g[n - l - i])
    # compute mex (minimum excluded value)
    m = 0
    while m in s:
        m += 1
    g.append(m)

for t in xrange(int(raw_input().strip())):
    raw_input()
    ret = 0
    # split the pins into groups and xor the SG values
    for p in raw_input().strip().split('X'):
        ret ^= g[len(p)]
    print 'WIN' if ret else 'LOSE'
