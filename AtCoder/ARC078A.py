n, a = int(input()), [int(i) for i in input().split()]

x, y = a[0], sum(a[1:])
ans = abs(x - y)

for i in a[1:-1]:
    x += i
    y -= i
    ans = min(ans, abs(x - y))

print(ans)
