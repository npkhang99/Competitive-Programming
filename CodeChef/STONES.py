# CodeChef
for T in range(int(input())):
    s, t, ans = set([i for i in input()]), input(), 0
    for i in t:
        if i in s:
            ans += 1
    print(ans)
