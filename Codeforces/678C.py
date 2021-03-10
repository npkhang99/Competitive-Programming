inp = input().split()
n, a, b, p, q = int(inp[0]), int(inp[1]), int(inp[2]), int(inp[3]), int(inp[4])

t, c = a, b
r = t % c
while r != 0:
    t = c
    c = r
    r = t % c

c = (a * b) // c
ans = 0
cnt = n // c
ans += (n // c) * max(p, q)
ans += (n // a - cnt) * p
ans += (n // b - cnt) * q

print(ans)
