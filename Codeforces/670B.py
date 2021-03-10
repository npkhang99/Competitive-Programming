inp = input().split()
n, k = int(inp[0]), int(inp[1])
a = input().split()

i = 1
while k - i > 0:
    k -= i
    i += 1

print(a[k - 1])
