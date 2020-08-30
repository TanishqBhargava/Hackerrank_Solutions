import sys
inlist = sys.stdin.readlines()
queryCount = int(inlist[0].strip())

start = 1
end = int(inlist[start].strip()) * 2 + 1

for i in range(queryCount):
    qsum = 0
    #read list one matrix at a time
    tgtMx = []
    n = int(inlist[start].strip())
    for j in inlist[start+1:end+1]:
        tgtMx.append(list(map(int, j.strip().split())))
    start = end + 1
    if i != queryCount-1:
        end = start + int(inlist[start].strip()) * 2 
    #sum logic to find quadrant max
    for x in range(n):
        for y in range(n):
            qsum += max(tgtMx[x][y], tgtMx[x][2*n-1-y], tgtMx[2*n-1-x][y], tgtMx[2*n-1-x][2*n-1-y])
    print(qsum)
