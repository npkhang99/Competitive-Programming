import math

st = input()

ans = 0.0

i, j = 0, len(st)-1

while i<=j:
    while i<len(st) and st[i]=='0': i+=1
    while j>=0 and st[j]=='1': j-=1
    if i>j: break
    ans += math.sqrt(j-i)
    i+=1; j-=1

print(ans)
