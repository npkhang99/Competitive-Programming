import math

inp = input().split()
a, b, c = int(inp[0]), int(inp[1]), int(inp[2])

n = math.ceil(a / c)
m = math.ceil(b / c)

print(n * m)
