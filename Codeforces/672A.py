n = int(input())
i=0
s=''

while len(s)<n:
    i+=1
    s+=str(i)

print(s[n-1])