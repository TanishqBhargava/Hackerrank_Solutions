def taumBday(b, w, bc, wc, z):
    if abs(bc-wc)<=z:
        return b*bc+w*wc
    elif bc<wc:
        return b*bc+w*(bc+z)
    else:
        return w*wc+b*(wc+z)

for _ in range(int(input())):
    b,w = map(int,input().split())
    bc,wc,z = map(int,input().split())
    print(taumBday(b, w, bc, wc, z))
