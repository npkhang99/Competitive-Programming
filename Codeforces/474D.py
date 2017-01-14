MOD = 1000000007

inp = input().split()
n,k = int(inp[0]),int(inp[1])

a,L = [0],[0]

for i in range(1,100001):
    if i<k: a.append(1)
    elif i==k: a.append(2)
    else: a.append(a[i-1]+a[i-k])
    L.append(L[i-1]+a[i])

for i in range(n):
    inp = input().split()
    x,y = int(inp[0]),int(inp[1])
    print((L[y]-L[x-1])%MOD)