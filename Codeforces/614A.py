import math

inp = input().split()
l,r,n = int(inp[0]),int(inp[1]),int(inp[2])

curr,found = 1,False

for i in range(round(math.log(r,n))+1):
    if i>0: curr *= n
    if l<=curr and curr<=r:
        print(int(curr),end=' ')
        found = True

if not found: print(-1)
else: print()
