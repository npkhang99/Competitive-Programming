import sys

cnt=0
for line in sys.stdin:
    for ch in line:
        if ch=='\"':
            if not cnt%2: print('``',end='')
            else: print('\'\'',end='')
            cnt+=1
        else: print(ch,end='')
