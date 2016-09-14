inp = input().split()
s,n = int(inp[0]),int(inp[1])

a = []

for i in range(n):
    inp = input().split()
    inp[0],inp[1] = int(inp[0]),int(inp[1])
    a.append(inp)

a = sorted(a, key=lambda k: (k[0],-k[1]))

ans = 0

for i in a:
    if s>i[0]:
        ans+=1
        s += i[1]

if ans==n: print('YES')
else: print('NO')
