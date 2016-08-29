def fact(x):
	a = {2:0, 3:0, 5:0}
	y = 2
	while y<=5:
		while x%y==0:
			a[y]+=1
			x/=y
		y+=1
	return a

n = int(input())
if n<3:
	print(-1)
	exit(0)
if(n%2==1):
	m = (n*n)//2
	k = m+1
	print(m,k)
	exit(0)

a = fact(n)
if a[2]>1:
	m = 3*(n//4) 
	k = 5*(n//4) 
	print(m,k)
elif a[3]>0:
	m = 4*(n//3) 
	k = 5*(n//3) 
	print(m,k)
elif a[5]>0:
	m = 4*(n//5) 
	k = 3*(n//5) 
	print(m,k)
else:
	m = (n*n)//4-1
	k = (n*n)//4+1
	print(m,k)
