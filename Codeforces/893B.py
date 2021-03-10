n = int(input())

ans = 1
for i in range(2, n + 1):
    for k in range(1, 18):
        x = (2 ** k - 1) * (2 ** (k - 1))
        if n % x == 0:
            ans = x

print(ans)
