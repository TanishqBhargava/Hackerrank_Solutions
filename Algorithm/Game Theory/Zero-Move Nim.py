for t in range(int(input())):
    input()
    y = 0
    for z in input().split():
        x = int(z)
        if x%2:
            x+=1
        else:
            x-=1
        y^=x
    if y:
        print ("W")
    else:
        print ("L")
