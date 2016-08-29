n = int(input())

a = [int(i) for i in input().split()]

moves = 0

for i in range(n):
	moves += a[i]-1
	if moves==0 or moves%2==0: print(2)
	else: print(1)
