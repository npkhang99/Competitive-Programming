n = int(input())
a = [int(i) for i in input().split()]

prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59]
fact = [-1]

for i in range(1,61):
	fact.append(0)
	for j in range(17):
		if not i%prime[j]: fact[i]=fact[i] | (1<<j)

# Goi dp[i][mask] tong gia tri |a[k]-b[k]| (k : 1 -> i)
# nho nhat ma i phan tu ban dau cua day b chia het cho cac uoc trong tap mask

dp = [[0 for j in range(1<<18)] for i in range(n+1)]

for i in range(1,n+1):
	for mask in range(1<<17):
		dp[i][mask] = 1000
		for x in range(1,61):
			if fact[x]|mask == mask:
				dp[i][mask] = min(dp[i][mask], dp[i-1][mask-fact[x]] + abs(a[i-1]-x))

sum,m = int(10E8),0
for mask in range(1<<17):
	if sum > dp[n][mask]:
		sum,m = dp[n][mask],mask

ans = []
for i in range(1,n+1,-1):
	for x in range(1,61):
		if fact[x]|m == m and dp[i-1][m-fact[x]]+abs(a[i-1]-x) == dp[i][m]:
			ans.insert(0,x)
			m-=fact[x]
			break

for i in ans: print(i,end=' ')
