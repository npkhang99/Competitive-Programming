a,b = [int(i) for i in input().split()]

if a % 3 == 0 or b % 3 == 0 or (a + b) % 3 == 0:
    print('Possible')
else:
    print('Impossible')
