def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b)

for T in range(int(raw_input())):
    a,b = [int(i) for i in raw_input().split('/')]
    c = gcd(a,b)
    print('Case '+str(T+1)+': '+str(a//c)+'/'+str(b//c))
