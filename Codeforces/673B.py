inp = input().split()
n, m = int(inp[0]), int(inp[1])

if n == 2:
    print(1)
    exit(0)

n += 1

if n % 2 == 1:
    _n = n // 2 + 1
    __n = _n
else:
    _n = n // 2
    __n = _n + 1

a = [[] for _ in range(n)]


def sameDiv(u, v):
    return (
        (u > 0 and u < __n and v > 0 and v < __n)
        or (u >= __n and u < n and v >= __n and v < n)
    ) and (u != _n and v != _n)


for i in range(m):
    inp = input().split()
    u, v = int(inp[0]), int(inp[1])
    if sameDiv(u, v):
        print(0)
        exit(0)
    a[u].append(v)
    a[v].append(u)

for i in range(_n):
    for j in a[i]:
        if j > 0 and j < _n:
            print(0)
            exit(0)

for i in range(__n, n):
    for j in a[i]:
        if j < n and j >= __n:
            print(0)
            exit(0)

if n % 2 == 1:
    print(1)
    exit(0)

similarTo = 0
ans = 2

for i in a[_n]:
    if (i in range(_n)) and similarTo != 1:
        similarTo += 1
    if (i in range(__n, n)) and similarTo != 2:
        similarTo += 2
    if similarTo == 3:
        break

if similarTo == 3:
    ans = 0
elif similarTo == 1 or similarTo == 2:
    ans = 1

print(ans)
