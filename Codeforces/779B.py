n,k = [int(i) for i in input().split()]

if n % 10 ** k == 0:
    print(0)
    exit(0)

if str(n).count('0') < k:
    print(len(str(n)) - 1)
    exit(0)

ans = 0

st = str(n)
j = len(st)-1

while int(st) % 10 ** k != 0:
    while int(st) % 10 ** k != 0 and st[j] != '0':
        st = st[:j] + st[j+1:]
        j -= 1
        ans += 1

    while int(st) % 10 ** k != 0 and st[j] == '0':
        j-=1

print(ans)
