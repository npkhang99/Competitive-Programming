n = int(raw_input())

a, ans = {}, 0
for i in range(n):
    inp = raw_input().split()
    if not inp[2].lower() in a:
        a[inp[2].lower()] = []
    if not inp[0].lower() in a:
        a[inp[0].lower()] = []
    a[inp[2].lower()].append(inp[0].lower())


def DFS(s, h):
    global ans
    ans = max(ans, h)
    for i in a[s]:
        DFS(i, h + 1)


DFS("polycarp", 1)

print(ans)
