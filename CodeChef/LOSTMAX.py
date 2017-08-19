for T in range(int(input())):
    a = [int(i) for i in input().split()]
    n = len(a) - 1
    for i in range(n + 1):
        if a[i] == n:
            a.pop(i)
            break
    a = sorted(a)
    print(a[-1:][0])
