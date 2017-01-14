n = int(raw_input())
a = [int(i) for i in raw_input().split()]

ans, curr = 0,0
for i in a:
    if i!=curr: ans+=abs(i-curr)
    curr = i

print(ans)