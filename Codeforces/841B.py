n = int(input())
a = [int(i) for i in input().split()]

cnt = 0
for i in a:
    if i % 2 == 1:
        cnt += 1

if cnt == 0:
    print('Second')
else:
    print('First')
