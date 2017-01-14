n = int(input())
if n>26:
    print('-1')
    exit(0)
s = input()
a = []
ans = 0

for i in s:
    if not i in a: a.append(i)
    else: ans+=1

print(ans)