n = int(input())
st = [input() for i in range(n)]
ans = False

for i in range(n):
    if st[i][0] + st[i][1] == "OO":
        ans = True
        st[i] = "++" + st[i][2:]
        break
    if st[i][3] + st[i][4] == "OO":
        ans = True
        st[i] = st[i][:3] + "++"
        break

if ans:
    print("YES")
    for s in st:
        print(s)
else:
    print("NO")
