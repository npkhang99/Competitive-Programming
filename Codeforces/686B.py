n = int(input())
a = [int(i) for i in input().split()]

def isSorted():
    for i in range(1,n):
        if a[i]<a[i-1]: return False
    return True

while not isSorted():
    b = []
    k = 0
    i = 1
    while i<n:
        if a[i]<a[i-1]:
            if k!=0 and i-1-b[k-1][1]==1:
                b[k-1][1]=i
            else:
                b.append([i-1,i])
                k+=1
            a[i],a[i-1]=a[i-1],a[i]
            i+=2
        else: i+=1
    for i in b:
        print(i[0]+1,i[1]+1)