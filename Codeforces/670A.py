n = int(input())

if n < 6: print(0, end=' ')
elif n%7 == 6: print((n//7)*2+1, end=' ')
else: print((n//7)*2, end=' ')

if n < 3: print(n)
else:
    ans = 2
    n-=2
    if n%7 == 6: ans+=(n//7)*2+1
    else: ans+=(n//7)*2
    print(ans)
