# a,b,c = int(input()),int(input()),int(input())
inp, out = open("TNHTest.inp", "r"), open("TNHTest.out", "w")

a, b, c = [int(i) for i in inp.read().split()]

out.write(str(pow(a, b, c)))
# print(pow(a,b,c))
