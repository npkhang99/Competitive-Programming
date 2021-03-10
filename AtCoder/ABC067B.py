n, k = [int(i) for i in input().split()]
print(-sum(sorted([-int(i) for i in input().split()])[:k]))
