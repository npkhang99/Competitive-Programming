inp = open("Ngoac.inp", "r")
# out = open("Ngoac.out","w")

st = inp.read()
stack = []

for i in range(len(st)):
    if st[i] == ")":
        print(stack.pop() + 1, i + 1)
    else:
        stack.append(i)
