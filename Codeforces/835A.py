s, v1, v2, t1, t2 = map(int, input().split())

p1 = t1 * 2 + v1 * s
p2 = t2 * 2 + v2 * s

if p1 < p2:
    print("First")
elif p1 > p2:
    print("Second")
else:
    print("Friendship")
