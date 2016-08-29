n = int(input())

for i in range(n):
    inp = input().split()
    a,b = int(inp[0]),int(inp[1])
    if a<b: print("<")
    elif a>b: print(">")
    else: print("=")
