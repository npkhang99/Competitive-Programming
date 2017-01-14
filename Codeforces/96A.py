st = input()

cnt = 1

for i in range(1,len(st)):
    if st[i]==st[i-1]:
        cnt+=1
        if(cnt>6):
            print('YES')
            exit(0)
    else: cnt=1

print('NO')
