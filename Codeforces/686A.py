inp = input().split()
n,x = int(inp[0]),int(inp[1])

cnt = 0

for i in range(n):
	inp = input().split()
	c,d = inp[0],int(inp[1])
	if c=='+': x+=d; continue;
	if d>x: cnt+=1; continue;
	x-=d;

print(x,cnt)