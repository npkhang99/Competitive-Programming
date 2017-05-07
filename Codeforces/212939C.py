import math

n = int(input()) - 2
n_fact = math.factorial(n)
ans = 0
for k in range(n+1):
    ans += n_fact // math.factorial(n-k)

print(ans)
