n = int(input())
x = input().split()
a = {}
m = 0

for i in x:
    if not i in a:
        a[i] = 1
    else:
        a[i] += 1
    m = max(m, a[i])

print(n - m)
