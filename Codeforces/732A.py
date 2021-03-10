k, r = [int(i) for i in input().split()]

ans, n = 1, k % 10

while n != r and n != 0:
    n = (n + k) % 10
    ans += 1

print(ans)
