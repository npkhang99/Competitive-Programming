n = int(input())

for _ in range(n):
    st = input()
    mem = [0,0]
    for i in st:
        if i=='M': mem[0]+=1
        elif i=='F': mem[1]+=1
    if mem[0]==mem[1] and len(st.split())>1: print('LOOP')
    else: print('NO LOOP')