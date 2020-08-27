def check(i):
    sq = str(i**2)
    le = len(str(i))
    r = sq[-le:]
    l = sq[:-le] or '0'
    return sum(map(int,(l,r)))==i

def kaprekarNumbers(p, q):
    return [i for i in range(p,q+1) if check(i)]

p = int(input())
q = int(input())
print(*kaprekarNumbers(p, q) or ["INVALID RANGE"])
