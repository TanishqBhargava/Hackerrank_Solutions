from itertools import combinations_with_replacement as cwr

if __name__ == '__main__':
    for _ in range(int(input())):
        n, k = list(map(int, input().rstrip().split()))
        a = sorted(list(map(int, input().rstrip().split())))
        values = [a[0]//k]
        combinations = {}
        for i in a[1:]:
            if combinations.setdefault(i,0) > 0:
                combinations[i] -= 1
            else:
                combinations[i] -= 1
                new_val = i - (values[0]*(k-1))
                for j in range(k):
                    for new_comb in map(lambda x: (k-j)*new_val + sum(x), cwr(values, j)):
                        combinations[new_comb] = combinations.get(new_comb, 0) + 1
                values.append(new_val)
        print(*values)
