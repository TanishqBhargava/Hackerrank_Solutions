def separateNumbers(s):
    start,stop = 1,len(s)//2+1
    while start<stop:
        for i in range(start,stop):
            new = s[:i]+str(int(s[:i])+1)
            if s.startswith(new):
                break
        n = ""
        arr=[int(s[:i])]
        while len(n)<len(s):
            n+=str(arr[-1])
            arr.append(arr[-1]+1)
        start=i+1
        if n ==s:
            return "YES "+s[:i]
    return "NO"

for _ in range(int(input())):
    print(separateNumbers(input()))
