inp = input().split()
n, t = int(inp[0]), int(inp[1])

a = [[0 for i in range(n + 1)] for j in range(n + 1)]

a[0][0] = t
for i in range(n):
    for j in range(i + 1):
        if a[i][j] >= 1:
            a[i + 1][j] += (a[i][j] - 1) / 2
            a[i + 1][j + 1] += (a[i][j] - 1) / 2

count = 0
for i in range(n):
    for j in a[i]:
        if j >= 1:
            count += 1

print(count)
