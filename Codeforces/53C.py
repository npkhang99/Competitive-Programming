n = int(input())

i,j = 1,n

while i<=j:
    if i<j: print(i,j,end=' ')
    else: print(i,end=' ')
    i+=1
    j-=1