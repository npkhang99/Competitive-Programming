import math

pi = math.pi

inp = input().split()
d,h,v,e = int(inp[0]),int(inp[1]),int(inp[2]),int(inp[3])

s = (d*d*pi)/4
r = s*e

if v<=r: print("NO")
else:
	ans = (s*h)/(v-r)
	print("YES\n",ans,sep='')