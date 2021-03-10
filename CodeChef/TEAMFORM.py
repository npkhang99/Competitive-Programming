TC = int(input())

for _ in range(TC):
    n, m = [int(i) for i in input().split()]
    for i in range(m):
        input()
    if n % 2 == 0:
        print("yes")
    else:
        print("no")
