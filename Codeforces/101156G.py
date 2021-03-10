n = int(input())

if n < 4:
    print(0)
    exit(0)

if n % 2 == 0:
    ans = n * (n - 2) ** 2 * (2 * n ** 3 - 12 * n ** 2 + 23 * n - 10) // 12
else:
    ans = (
        (n - 1)
        * (n - 3)
        * (2 * n ** 4 - 12 * n ** 3 + 25 * n ** 2 - 14 * n + 1)
        // 12
    )

print(ans)
