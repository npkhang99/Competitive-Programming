n,k,a,b = [int(i) for i in input().split()]
ans = ''

if abs(a-b) <= 1:
    if a >= b:
        f,s = 'G','B'
    else:
        f,s = 'B','G'
    for i in range(n):
        if i % 2 == 0:
            ans += f
        else:
            ans += s
    print(ans)
    exit(0)

cnt, f, s = 0, 'G', 'B'
if a < b:
    f, s = 'B', 'G'

c = max(a,b) // min(a+1,b+1)

if c > k:
    print('NO')
    exit(0)

r = max(a,b) % min(a+1,b+1)

if r > 0 and c == k:
    print('NO')
    exit(0)

x = 0
for i in range(n):
    if x + 1 <= c:
        ans += f
        x += 1
    elif r > 0 and x == c:
        ans += f
        x += 1
        r -= 1
    else:
        ans += s
        x = 0

print(ans)
