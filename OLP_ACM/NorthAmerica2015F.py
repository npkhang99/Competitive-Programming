alphabet = set(chr(i) for i in range(ord('a'), ord('z')+1))

for T in range(int(input())):
    st = set(input().replace(' ','').strip(' .,!?`\'"').lower())
    if len(alphabet - st) != 0:
        left = ''
        for i in (alphabet - st):
            left += i
        left = sorted(left)
        print('missing ', end='')
        for i in left:
            print(i,end='')
        print()
    else:
        print('pangram')
