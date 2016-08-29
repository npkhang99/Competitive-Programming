n = int(input())
st = input()
a = [int(i) for i in input().split()]

for i in range(n-1):
	if(a[i]==a[i+1]):
		print(0)
		exit(0)

ans = 10**9
for i in range(n-1):
	if st[i]=='R' and st[i+1]=='L': ans = min(ans,(a[i+1]-a[i])//2)

if ans!=10**9: print(ans)
else: print(-1)