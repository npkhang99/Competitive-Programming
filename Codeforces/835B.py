k = int(input())
a = sorted([int(i) for i in input()])

s = sum(a)
ans = 0

while s < k:
    s += 9 - a[ans]
    ans += 1

print(ans)
