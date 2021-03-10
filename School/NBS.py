inp = open("NBS.inp", "r")
out = open("NBS.out", "w")

n, t, s = int(inp.readline()), int(inp.readline()), inp.readline()

if n % 2 == 0:
    t = t // 2 - 1

t = str(bin(t)).split("b")[1]
t = "0" * (n - len(t)) + t

if n % 2 == 0:
    s = s[:-1]
    s = int(s, 2) // 2 + 1
else:
    s = int(s, 2) + 1

s %= 111539786

print(t, s, sep="\n")
out.write(t + "\n" + str(s) + "\n")
