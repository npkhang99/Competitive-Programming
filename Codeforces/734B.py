a = [int(i) for i in input().split()]

ans = 0

if a[0] > 0 and a[2] > 0 and a[3] > 0:
    ans += 256*min(a[0],a[2],a[3])
    a[0] -= min(a[0],a[2],a[3])
    a[2] -= min(a[0],a[2],a[3])
    a[3] -= min(a[0],a[2],a[3])

if a[0] > 0 and a[1] > 0:
    ans += 32*min(a[0],a[1])
    a[0] -= min(a[0],a[1])
    a[1] -= min(a[0],a[1])

print(ans)
