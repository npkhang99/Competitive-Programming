inp = input().split()
n, m = int(inp[0]), int(inp[1])

if n == 1 and m == 1:
    print(0)
    exit(0)

ans = max(
    n // 2 * m + (n - n // 2 * 2) * (m // 2),
    m // 2 * n + (m - m // 2 * 2) * (n // 2),
)

print(ans)
