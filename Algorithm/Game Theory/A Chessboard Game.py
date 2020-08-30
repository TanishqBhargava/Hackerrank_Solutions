def game(x, y):
    ''' returns win/lose in boolean '''
    if 1<=x<=15 and 1<=y<=15:
        return not game(x-2, y+1) or not game(x-2, y-1) or not game(x+1, y-2) or not game(x-1, y-2)
    else:
        return True

def main():
    t = int(input())
    for _ in range(t):
        x, y = map(int, input().split())
        print('First' if game(x, y) else 'Second')
        
main()
