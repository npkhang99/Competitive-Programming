n = int(input())

a = [0,0]

for i in range(n):
	inp = input().split()
	if inp[0] > inp[1]: a[0]+=1
	elif inp[0] < inp[1]: a[1]+=1

if a[0]>a[1]: print('Mishka')
elif a[0]<a[1]: print('Chris')
else: print('Friendship is magic!^^')
