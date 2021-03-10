n = int(input())
a = [int(input()) for i in range(n)]

p1, p2, p3 = 1, 2, 3
for i in a:
    if p1 != i and p2 != i:
        print("NO")
        exit(0)
    elif p1 != i:
        p1, p3 = p3, p1
    else:
        p2, p3 = p3, p2

print("YES")
