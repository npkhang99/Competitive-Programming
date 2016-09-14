inp = input().split()
a,b = int(inp[0]),int(inp[1])

ans = 0

while a>0 and b>0:
    if a<2 and b<2: break
    ans+=1
    a,b = max(a,b), min(a,b)
    a-=2; b+=1

print(ans)