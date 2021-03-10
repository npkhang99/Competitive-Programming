import math, sys, itertools

st, cnt = input(), [0 for i in range(256)]
n = len(st)

for c in st:
    cnt[ord(c)] += 1

x = 1

for i in range(ord("a"), ord("z") + 1):
    if cnt[i] > 1:
        x *= math.factorial(cnt[i])

ways = str(math.factorial(n) // x)

# print(ways, file = sys.stderr)
# print(len(set([perm for perm in itertools.permutations([c for c in st])])), file = sys.stderr)

ans = 0
for c in ways[::-1]:
    if c == "0":
        ans += 1
    else:
        break

print(ans)
