n,st = int(input()), input()

ans,flag = '',0
for i in range(n):
    if i < flag:
        continue
    if st[i] != 'o':
        ans += st[i]
        continue
    curr = 'o'
    pos = i
    for j in range(i+1,n,2):
        if st[j:j+2] == 'go':
            pos = j+2
        else:
            break
    if pos > i:
        ans += '***'
        flag = pos
    else:
        ans += st[i]

print(ans)
