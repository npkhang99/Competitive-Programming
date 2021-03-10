po = []
for i in range(32):
    po.append(2 ** i)

T = int(input())
for _ in range(T):
    n = int(input())
    if n % 2 == 1:
        ans = (1 + n) * (n // 2) + (n + 1) // 2
    else:
        ans = (1 + n) * (n // 2)
    for i in po:
        if i <= n:
            ans -= i * 2
    print(ans)
