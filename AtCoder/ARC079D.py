k = int(input())

if k == 0:
    print("2\n1 1")
    exit(0)

if k == 1:
    print("2\n2 0")
    exit(0)

n = min(50, k)
a = [i for i in range(n)]
c = k // n

for i in range(n):
    a[i] += c

for i in range(k % n):
    a[i] += n
    for j in range(n):
        if i != j:
            a[j] -= 1

print(n)
for i in a:
    print(i, end=" ")
print()
