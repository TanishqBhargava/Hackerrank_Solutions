from collections import deque
def legal_moves(x):
    for i in range(len(x)):
        if x[i]:
            for j in range(len(x)):
                if not x[j] or x[i][-1] < x[j][-1]:
                    yield (i, j)

def is_goal(x):
    return all([len(x[i]) == 0 for i in range(1, len(x))])

def bfs(x):
    def tuplify(z):
        return tuple(tuple(t) for t in z)

    def do_move(g, m):
        y = [list(t) for t in g]
        y[m[1]].append(y[m[0]].pop())
        # WLOG sort 2nd-4th stacks by order of largest disk
        y[1:4] = sorted(y[1:4], key=lambda t: t[-1] if t else 0)  
        return tuplify(y)
    visited = set()
    start = (tuplify(x), 0)
    q = deque([start])
    visited.add(start)
    while q:
        node, depth = q.popleft()
        if is_goal(node):
            return depth
        for move in legal_moves(node):
            child = do_move(node, move)
            if child not in visited:
                visited.add(child)
                q.append((child, depth+1))

# load the representation from stdin
N = int(raw_input())
A = [[] for i in range(4)]
R = [int(t) for t in raw_input().split()]
for i in range(N):
    A[R[i]-1] = [(i+1)] + A[R[i]-1]
print bfs(A)
