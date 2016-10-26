import math

place = {
    'f': 1,
    'e': 2,
    'd': 3,
    'a': 4,
    'b': 5,
    'c': 6
}

st = input()
row = int(st[:-1]) - 1
seat = st[-1:]

ans = 16*(row // 4)
if row % 4 in [1,3]:
    ans += 7

ans += place[seat]

print(ans)
