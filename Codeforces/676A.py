n = int(input())
a = [int(i) for i in input().split()]

for i in range(n):
    if a[i] == 1:
        vt1 = i
    if a[i] == n:
        vtn = i

print(max(abs(0 - vtn), abs(0 - vt1), abs(n - vt1 - 1), abs(n - vtn - 1)))
