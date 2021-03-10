s = input()
MOD = 10 ** 9 + 7
a = {}
b = []
k = 0
# 0 -> 9
for i in range(ord("0"), ord("9") + 1):
    a[chr(i)] = k
    k += 1
    b.append(chr(i))
# A -> Z
for i in range(ord("A"), ord("Z") + 1):
    a[chr(i)] = k
    k += 1
    b.append(chr(i))
# a -> z
for i in range(ord("a"), ord("z") + 1):
    a[chr(i)] = k
    k += 1
    b.append(chr(i))
# - _
a["-"], a["_"] = 62, 63
b.append("-")
b.append("_")

cnt = {}
for i in b:
    cnt[i] = 0

for i in b:
    for j in b:
        cnt[b[a[i] & a[j]]] += 1

ans = 1
for i in s:
    ans = (ans * cnt[i]) % MOD
print(ans)
