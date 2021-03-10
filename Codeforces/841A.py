n, k = [int(i) for i in input().split()]
s = input()

for i in range(ord("a"), ord("z") + 1):
    x = 0
    for j in s:
        if ord(j) == i:
            x += 1
    if x > k:
        print("NO")
        exit(0)

print("YES")
