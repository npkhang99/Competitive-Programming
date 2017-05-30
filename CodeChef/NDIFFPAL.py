# CodeChef
alph = 'abcdefghijklmnopqrstuvwxyz'

for TC in range(int(input())):
    n = int(input())
    print(alph*(n//len(alph)) + alph[:n%len(alph)])
