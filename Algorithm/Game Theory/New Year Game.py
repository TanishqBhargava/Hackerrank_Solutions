for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    new_arr=[x%3 for x in arr]
    n_1=new_arr.count(1)
    n_2=new_arr.count(2)
    print('Balsa') if (n_1&1)|(n_2&1) else print('Koca')
