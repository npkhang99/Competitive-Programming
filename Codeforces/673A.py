n = int(input())
inp = input().split()
a = []
for i in inp:
    a.append(int(i))

t = 0
i = 0
while i < n and a[i] - t <= 15:
    t = a[i]
    i += 1

print(min(90, t + 15))
