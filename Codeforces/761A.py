import math

a,b = [int(i) for i in input().split()]

if (a == 0 and b == 0) or abs(a-b) > 1:
    print('NO')
else:
    print('YES')
