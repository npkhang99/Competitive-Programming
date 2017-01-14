vowel = ['a','e','i','o','u','y']

n = int(input())
a = [int(i) for i in input().split()]

for i in range(n):
    st = input().split()
    cnt = 0
    for word in st:
        for j in word:
            if j in vowel: cnt+=1
    if cnt!=a[i]:
        print('NO')
        exit(0)

print('YES')
