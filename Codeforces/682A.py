inp = input().split()
n, m = int(inp[0]), int(inp[1])

ans = 0

for i in range(n):
    ans += (m + i + 1) // 5 - (i + 1) // 5

print(ans)
