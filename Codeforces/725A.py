n,st = int(input()),input()

i = 0
ans = 0
while i<n and st[i] == '<':
    ans += 1
    i += 1

i = n-1
while i>=0 and st[i] == '>':
    ans += 1
    i -= 1

print(ans)
