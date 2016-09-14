st = input()

a = []
ans = 0

for i in st:
    if not i in a:
        ans+=1
        a.append(i)

if ans%2: print('IGNORE HIM!')
else: print('CHAT WITH HER!')