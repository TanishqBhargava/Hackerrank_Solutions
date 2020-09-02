def countLuck(matrix, k):
    turns = 0
    ron = positionRon(grid)
    size = findLargestRegion(grid, ron[0], ron[1], turns)
    if size==k:
        return "Impressed"
    return "Oops!"

def positionRon(matrix):
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 'M':
                return [i,j]

def findLargestRegion(grid, row, col, turns):
    if row<0 or row>=rows or col<0 or col>=cols:
        return None
    elif grid[row][col]=='X':
        return None
    elif grid[row][col]=='*':
        return turns
    path = 0
    if not row-1<0:
        if grid[row-1][col]=='.' or grid[row-1][col]=='*':
            path += 1
    if not row+1>=rows:
        if grid[row+1][col]=='.' or grid[row+1][col]=='*':
            path += 1
    if not col-1<0:
        if grid[row][col-1]=='.' or grid[row][col-1]=='*':
            path += 1
    if not col+1>=cols:
        if grid[row][col+1]=='.' or grid[row][col+1]=='*':
            path += 1
    if path>1:
        turns+=1
        grid[row][col]='1'
    else:
        grid[row][col]='0'
    for x in [[row-1, col], [row+1, col], [row, col-1], [row, col+1]]:
        r = x[0]
        c = x[1]
        if r<0 or r>=rows or c<0 or c>=cols:
            continue
        if grid[r][c] == '1' or grid[r][c] == '0':
            continue
        size = findLargestRegion(grid, r, c, turns)   #RECURSION CALL!
        if size==None:
            continue
        else:
            return size

t = int(input())
for _ in range(t):
    rows, cols = map(int,input().split(' ')) 
    grid = []
    for i in range(rows):
        grid.append(list(input()))
    k = int(input())
    print(countLuck(grid,k))
