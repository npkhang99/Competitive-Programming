T = int(input())
for i in range(T):
    n = [int(i) for i in input().split()]
    if n[0] % 2 + n[1] % 2 == 2:
        print('Hussain')
    else:
        print('Hasan')
