inp = input().split()
a,b,c = int(inp[0]),int(inp[1]),int(inp[2])

if a==b:
    print("YES")
    exit(0)

if c==0 and a!=b:
    print("NO")
    exit(0)

if c>0 and a<b:
    if (b-a)%c==0: print("YES")
    else: print("NO")
    exit(0)

if c<0 and a>b:
    if (b-a)%c==0: print("YES")
    else: print("NO")
    exit(0)

print("NO")