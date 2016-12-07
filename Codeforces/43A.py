n = int(input())

a = {}
a[''] = -1
for i in range(n):
    s = input()
    if not s in a: a[s]=0
    else: a[s]+=1

ans = ''
for i in a:
    if a[ans]<a[i]: ans=i

print(ans)
