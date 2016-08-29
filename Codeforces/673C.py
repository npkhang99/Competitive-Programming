n = int(input())
a = [int(i) for i in input().split()]

firstOccur = {}
for i in range(n):
	if not a[i] in firstOccur: firstOccur[a[i]] = i

ans = [0 for i in range(n)]

for i in range(n):
	for j in range(i,n):
		