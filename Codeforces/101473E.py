n, m = [int(i) for i in input().split()]
if n == m:
    print("*")
    exit(0)
returned = set()
for i in [int(i) for i in input().split()]:
    returned.add(i)

lost = False
for i in range(1, n + 1):
    if i not in returned:
        lost = True
        print(i, end=" ")
print()
