n = int(input())

canSolve = ['1 1 1','1 1 0','1 0 1','0 1 1']
ans = 0

for i in range(n):
	inp = input()
	if inp in canSolve: ans+=1

print(ans)