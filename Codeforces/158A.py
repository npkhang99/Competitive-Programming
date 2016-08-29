inp = input().split()
n,k = int(inp[0]),int(inp[1])

a = [int(i) for i in input().split()]

ans=0

for i in a:
	if i>0 and i>=a[k-1]: ans+=1;

print(ans)