inp = input().split()
n,m = int(inp[0]), int(inp[1])
a = [[] for _ in range(n+1)]
for i in range(m):
	inp = input().split()
	x,y = int(inp[0]), int(inp[1])
	a[x-1].append(y-1)
	a[y-1].append(x-1)

dp = [1 for _ in range(n)]
for i in range(n):
	for j in range(len(a[i])):
		if(i<a[i][j]): dp[a[i][j]] = max(dp[a[i][j]],dp[i]+1)

ans = 0
for i in range(n):
	ans = max(ans, dp[i]*len(a[i]))

print(ans)
