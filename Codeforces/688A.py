inp = input().split()
n, d = int(inp[0]), int(inp[1])

a = ""
for i in range(n):
    a += "1"

ans, cnt = 0, 0

for i in range(d):
    st = input()
    if st == a:
        ans = max(ans, cnt)
        cnt = 0
    else:
        cnt += 1

print(max(ans, cnt))
