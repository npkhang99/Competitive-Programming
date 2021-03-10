l, r, x = [int(i) for i in input().split()]

i, a = 1, []
while i <= r:
    if i in range(l, r + 1):
        a.append(i)
    i *= x

if len(a) == 0:
    print(-1)
else:
    for i in a:
        print(i, end=" ")
    print()
