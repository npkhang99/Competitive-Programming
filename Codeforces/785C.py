def check(x):
    y = min(x-1, m)
    return x*(x+1)//2 >= n + y*(y+1)//2 + max(0, x-m-1) * m

def main():
    if n <= m:
        print(n)
        return 0
    l, r, ans = 1, 10**18, 0
    while l <= r:
        mid = (l + r) // 2
        if check(mid):
            ans = mid
            r = mid - 1
        else:
            l = mid + 1
    print(ans)
    return 0

if __name__ == "__main__":
    n, m = [int(i) for i in input().split()]
    main()
