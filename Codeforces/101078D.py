T = int(input())

for t in range(T):
    n = int(input())
    if n == 0:
        print(0)
        continue
    ans = 0
    ans += n - n // 2
    last = (n - 1) // 3
    ans += (n - n // 2) - (last - last // 2)
    print(ans)
