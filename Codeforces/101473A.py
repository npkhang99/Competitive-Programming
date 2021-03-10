a, b, c = [int(i) for i in input().split()]

if a == b == c:
    print("*")
elif a == b and b != c:
    print("C")
elif a == c and c != b:
    print("B")
else:
    print("A")
