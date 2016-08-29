inp = input().split()
n,a,b,c,d = int(inp[0]),int(inp[1]),int(inp[2]),int(inp[3]),int(inp[4])

def equal(e,a,b,c,d):
	return e+b-c<=n and e+a-d<=n and e+a+b-c-d<=n and e+b-c>0 and e+a-d>0 and e+a+b-c-d>0

count = 0

for e in range(1,n+1):
	if equal(e,a,b,c,d): count+=n

print(count)
