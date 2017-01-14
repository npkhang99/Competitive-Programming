n,st = int(input()), input()

if n % 2 == 0:
    s = 1
else:
    s = 0

ans = ''
for i in st:
    if s == 0:
        ans = ans + i
    else:
        ans = i + ans
    s = 1-s

print(ans)
