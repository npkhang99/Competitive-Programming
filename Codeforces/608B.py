a,b = input(),input()
memo = {}
ans = 0

for i in range(len(a),len(b)+1):
    s = b[i-len(a) : i]
    if s in memo:
        ans+=memo[s]
        continue
    t=0
    for j in range(len(a)):
        if s[j]!=a[j]: t+=1
    memo[s]=t
    ans+=t

print(ans)
