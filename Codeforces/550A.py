st = input()
ab,ba = [],[]

for i in range(len(st)-1):
	if st[i:i+2]=='AB': ab.append(i)
	elif st[i:i+2]=='BA': ba.append(i)

if ab==[] or ba==[]:
	print("NO")
	exit(0)

for i in ab:
	for j in ba:
		if abs(i-j)>1:
			print("YES")
			exit(0)
print("NO")
