T = int(input())

def sumRange(start,stop):
    ans = 0
    for i in range(start,stop+1):
        ans += i
    return ans

for t in range(T):
    n,k,b = [int(i) for i in input().split()]
    if n < sumRange(1,b) or n > sumRange(k-b+1,k):
        print(-1)
        continue

    a = [(i+1) for i in range(b)]
    currSum,i = sum(a),b-1

    while currSum!=n:
        need = min(k,n-currSum+a[i])
        currSum += -a[i]+need
        a[i] = need
        k-=1
        i-=1

    for i in range(b):
        if i==0: print(a[i],end='')
        else: print('',a[i],end='')

    print()
