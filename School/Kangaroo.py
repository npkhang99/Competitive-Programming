def y():
    print("YES")
    exit(0)


def n():
    print("NO")
    exit(0)


x1, v1, x2, v2 = [int(i) for i in input().split()]

if x1 == x2:
    y()

if x1 < x2:
    if v1 <= v2:
        n()
    x = x2 - x1
    v = v2 - v1
    if x % v == 0:
        y()
    else:
        n()

if v2 <= v1:
    n()
x = x1 - x2
v = v1 - v2
if x % v == 0:
    y()
else:
    n()
