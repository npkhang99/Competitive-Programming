st = raw_input()

upperCase, lowerCase = 0, 0

for i in st:
    if ord(i) in range(ord("A"), ord("Z") + 1):
        upperCase += 1
    if ord(i) in range(ord("a"), ord("z") + 1):
        lowerCase += 1

if upperCase > lowerCase:
    print(st.upper())
else:
    print(st.lower())
