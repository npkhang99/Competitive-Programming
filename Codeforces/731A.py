st = input()

c,ans = 'a',0
for i in st:
    ans += min(abs(ord(c)-ord(i)), 26-abs(ord(c)-ord(i)))
    c = i

print(ans)
