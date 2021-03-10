a, b = [int(i) for i in input().split()]
a1, b1 = [int(i) for i in input().split()]
a2, b2 = [int(i) for i in input().split()]


def check(a_c, b_c):
    return a_c <= a and b_c <= b


if (
    check(a1 + a2, max(b1, b2))
    or check(max(a1, a2), b1 + b2)
    or check(max(b1, b2), a1 + a2)
    or check(max(b1, a2), a1 + b2)
    or check(max(a1, b2), b1 + a2)
    or check(b1 + b2, max(a1, a2))
    or check(b1 + a2, max(a1, b2))
    or check(a1 + b2, max(b1, a2))
):
    print("YES")
else:
    print("NO")
