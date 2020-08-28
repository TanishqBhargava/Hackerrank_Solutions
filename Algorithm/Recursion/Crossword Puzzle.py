import re

def fullboard(mboard):
    for r in range(len(mboard)):
        for c in range(len(mboard[0])):
            if mboard[r][c] == '-':
                return False
    return True

def try_place(mboard, word,  room):
    len_is_right = len(word) == (room[3]-room[2])
    if not len_is_right:
        return False, None
    kind, n, s, e = room
    if kind == 'row':
        if not all((roomc == '-' or roomc == wordc) for wordc, roomc in \
                    zip(word, mboard[n][s:e])):
            return False, None
        saved = mboard[n][s:e]
        mboard[n][s:e] = word
    elif kind == 'col':
        if not all((roomc == '-' or roomc == wordc) \
                    for wordc, roomc in \
                    zip(word, [mboard[i][n] for i in range(s,e)])):
            return False, None
        wi = 0 # word index
        saved = tuple(mboard[i][n] for i in range(s,e))
        for i in range(s,e):
            mboard[i][n] = word[wi]
            wi += 1
    else:
        raise Exception('invalid kind (%s), should be "row" or "col"'%kind)

    return True, saved

def restore(mboard, ss, room):
    assert len(room) == 4
    kind, n, s, e = room
    assert len(ss) == (e-s)
    if kind == 'row':
        mboard[n][s:e] = ss
    elif kind == 'col':
        j = 0 # saved slice index
        for i in range(s,e):
            mboard[i][n] = ss[j]
            j += 1
    else:
        raise Exception('Invalid kind (%s), should be "row" or "col"'% kind)

def bprint(mbrd):
    for row in mbrd:
        print(''.join(row))

def place(mboard, words, rms):
    if fullboard(mboard) or len(words) == 0:
        bprint(mboard)
    else:
        assert len(rms) >= 1, "weird, no more rooms"
        for i,w in enumerate(words):
            placed_successful, saved_slice = try_place(mboard, w, rms[0])
            if placed_successful:
                place(mboard, words[:i]+words[i+1:], rms[1:])
                restore(mboard, saved_slice, rms[0])

def main():
    board=[]
    for _ in range(11):  # 11 including the cities line
        board.append(input().strip())
    words = board[-1].split(';')
    del board[-1]
    assert all(10 == len(s) for s in board), "not all rows have 10 chars"
    assert len(board) == 10, "not 10 rows, %d"%len(board)
    assert all(len(s) <=10 for s in words), "word len must be <=10"
    assert len(words) <=10, "too many words, need <=10"
    
    mb = [ list(s) for s in board ]
    rooms = []
    for r in range(len(board)):
         for matchobj in re.finditer(r'--+', board[r]):
             rooms.append(('row', r, matchobj.span()[0], matchobj.span()[1]))        
    for c in range(len(board[0])):
         vstr=''.join(board[row][c] for row in range(len(board)))
         for matchobj in re.finditer(r'--+', vstr):
             rooms.append(('col', c, matchobj.span()[0], matchobj.span()[1]))
            
    place(mb, words, rooms)

if __name__ == '__main__':
    main()
