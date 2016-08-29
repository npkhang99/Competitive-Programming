n = int(input())
a = [int(i) for i in input().split()]

pos,list = 0,[0]

for i in range(1,n):
	if a[i]<a[pos]:
		pos,list = i,[i]
	elif a[i]==a[pos]:
		list.append(i)

if len(list)==1:
	print(n-1-pos+n*a[pos]+pos)
	exit(0)
elif len(list)==n:
	print(a[0]*n)
	exit(0)

list.append(n+list[0])

pos,distance = 0,list[1]-list[0]
for i in range(1,len(list)-1):
	if list[i+1]-list[i]>distance:
		pos,distance = i,list[i+1]-list[i]

ans = n*a[list[pos]]+list[pos+1]-list[pos]-1

print(ans)
